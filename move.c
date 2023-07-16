#include <stdint.h>
#include <stdlib.h>
#include "defines.h"
#include <stddef.h>
#include "move.h"
#include "board.h"
#include "reward.h"

Inventory* getInventoryPermutations(Inventory* inv) {
    Inventory* perms = malloc(6 * sizeof(Inventory));

    perms[0].tiles[0] = inv->tiles[0];
    perms[0].tiles[1] = inv->tiles[1];
    perms[0].tiles[2] = inv->tiles[2];

    perms[1].tiles[0] = inv->tiles[0];
    perms[1].tiles[1] = inv->tiles[2];
    perms[1].tiles[2] = inv->tiles[1];

    perms[2].tiles[0] = inv->tiles[1];
    perms[2].tiles[1] = inv->tiles[0];
    perms[2].tiles[2] = inv->tiles[2];

    perms[3].tiles[0] = inv->tiles[1];
    perms[3].tiles[1] = inv->tiles[2];
    perms[3].tiles[2] = inv->tiles[0];

    perms[4].tiles[0] = inv->tiles[2];
    perms[4].tiles[1] = inv->tiles[1];
    perms[4].tiles[2] = inv->tiles[0];

    perms[5].tiles[0] = inv->tiles[2];
    perms[5].tiles[1] = inv->tiles[0];
    perms[5].tiles[2] = inv->tiles[1];

    return perms;
}

Inventory getRandomInventory() {
    Inventory inv = {
        .tiles = {getRandomTile(), getRandomTile(), getRandomTile()}
    };
    return inv;
}

void recBestMove(Inventory* inv, RowType* board, uint8_t layer, Move* bestMove, Move* currentMove) {
    //Hier bewerten
    if (layer == 0) {
        RewardType boardScore = judgeBoard(board);
        if(boardScore > bestMove->points) {
            bestMove->isPlaceable = 1;
            bestMove->points = boardScore;
            for (int i = 0; i < INVENTORY_SPACE; i++) {
                bestMove->moves[i] = currentMove->moves[i];
            }
        }
        return;
    }

    //Hier Platzieren und rekursiv aufrufen
    RowType* copiedBoardLayer[BOARD_HEIGTH];
    for (int index = 0; index < BOARD_WIDTH * BOARD_HEIGTH; index++) {
        int x = index % BOARD_WIDTH;
        int y = index / BOARD_WIDTH;
        
        copyBoard(copiedBoardLayer, board);
        Tile tile = inv->tiles[(INVENTORY_SPACE - layer)];
        if (!placeTileOnBoard(&tile, x, y, copiedBoardLayer)) continue;
        cleanFullRows(&tile, x, y, copiedBoardLayer);

        SingleMove move = {.tile = tile, .x_position = x, .y_position = y};
        currentMove->moves[(INVENTORY_SPACE - layer)] = move;

        recBestMove(inv, copiedBoardLayer, layer - 1, bestMove, currentMove);
        pasteBoard(copiedBoardLayer, board);
    }
}

Move getBestMove(Inventory* inv, RowType* board) {
    Move bestMove = {
        .moves = { NULL, NULL, NULL },
        .isPlaceable = 0,
        .points = 0
    };

    Inventory* perms = getInventoryPermutations(inv);

    //Permutation Loop
    for(uint8_t i = 0; i < 6; i++){
        Inventory permInv = perms[i];
        Move curMove = { .isPlaceable = 0, .points = 0 };
        recBestMove(&permInv, board, INVENTORY_SPACE, &bestMove, &curMove);
    }
    return bestMove;

}
