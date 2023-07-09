#include <stdint.h>
#include <stdlib.h>
#include "defines.h"
#include <stddef.h>
#include "move.h"
#include "board.h"

Inventory* getInventoryPermutations(Inventory inv) {
    Inventory* perms = malloc(6 * sizeof(Inventory));

    perms[0].tiles[0] = inv.tiles[0];
    perms[0].tiles[1] = inv.tiles[1];
    perms[0].tiles[2] = inv.tiles[2];

    perms[1].tiles[0] = inv.tiles[0];
    perms[1].tiles[1] = inv.tiles[2];
    perms[1].tiles[2] = inv.tiles[1];

    perms[2].tiles[0] = inv.tiles[1];
    perms[2].tiles[1] = inv.tiles[0];
    perms[2].tiles[2] = inv.tiles[2];

    perms[3].tiles[0] = inv.tiles[1];
    perms[3].tiles[1] = inv.tiles[2];
    perms[3].tiles[2] = inv.tiles[0];

    perms[4].tiles[0] = inv.tiles[2];
    perms[4].tiles[1] = inv.tiles[1];
    perms[4].tiles[2] = inv.tiles[0];

    perms[5].tiles[0] = inv.tiles[2];
    perms[5].tiles[1] = inv.tiles[0];
    perms[5].tiles[2] = inv.tiles[1];

    return &perms[0];
}

Inventory getRandomInventory() {
    Inventory inv = {
        .tiles = {getRandomTile(), getRandomTile(), getRandomTile()}
    };
    return inv;
}

Move getBestMove(Inventory inv) {
    SingleMove move1 = { .tile = emptyTile, .x_position = BOARD_WIDTH, .y_position = BOARD_HEIGTH };
    SingleMove move2 = { .tile = emptyTile, .x_position = BOARD_WIDTH, .y_position = BOARD_HEIGTH };
    SingleMove move3 = { .tile = emptyTile, .x_position = BOARD_WIDTH, .y_position = BOARD_HEIGTH };

    Move bestMove = {
        .moves = { move1, move2, move3 },
        .isPlaceable = 0
    };

    RewardType bestPoint;
    Inventory* perms = getInventoryPermutations(inv);

    //Permutation Loop
    for(uint8_t i = 0; i < 6; i++){
        Inventory permInv = perms[i];

        RowType* copiedBoardLayer1[BOARD_HEIGTH];
        copyBoard(copiedBoardLayer1);

        Tile firstTile = permInv.tiles[0];
        placeTileOnBoard(&firstTile, 0, 0);
        cleanFullRows(&firstTile, 0, 0);

        printBoard();

        pasteBoard(copiedBoardLayer1);
    }

    return bestMove;
}
