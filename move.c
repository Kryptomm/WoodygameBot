#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>
#include <stddef.h>

#include "defines.h"
#include "move.h"
#include "board.h"
#include "reward.h"

typedef struct {
    Inventory* inv;
    RowType* board;
    uint8_t layer;
    Move* bestMove;
    Move* currentMove;
} ThreadData;

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

void* recBestMoveStarter(void* arg) {
    ThreadData* threadData = (ThreadData*)arg;
    recBestMove(threadData->inv, threadData->board, threadData->layer,  threadData->bestMove, threadData->currentMove);
}

Move getBestMove(Inventory* inv, RowType* board) {
    Move* bestMoves[6] = { NULL, NULL, NULL, NULL, NULL, NULL };

    Inventory* perms = getInventoryPermutations(inv);
    My_pthread_t tid[6];

    //Permutation Loop
    for(uint8_t i = 0; i < 6; i++){
        Inventory permInv = perms[i];
        Move* curMove = (Move*)malloc(sizeof(Move)); // Allocate memory for curMove dynamically
        Move* bestMove = (Move*)malloc(sizeof(Move)); // Allocate memory for bestMove dynamically

        curMove->isPlaceable = 0;
        curMove->points = 0;
        bestMove->isPlaceable = 0;
        bestMove->points = 0;

        bestMoves[i] = bestMove;
        ThreadData data = {
            .inv = &permInv,
            .board = board,
            .layer = INVENTORY_SPACE,
            .bestMove = bestMove,
            .currentMove = curMove
        };

        //pthread_create(&tid[i], NULL, recBestMoveStarter, &data);
        recBestMove(&permInv, board, INVENTORY_SPACE, bestMove, curMove);
    }

    for(uint8_t i = 0; i < 6; i++){
        pthread_join(&tid[i], NULL);
    }

    Move realbestMove = *bestMoves[0];
    RewardType bestPoints = bestMoves[0]->points;
    for(uint8_t i = 0; i < 6; i++){
        if (bestMoves[i]->points > bestPoints) {
            bestPoints = bestMoves[i]->points;
            realbestMove = *bestMoves[i];
        }
    }

    return realbestMove;
}
