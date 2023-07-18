#include <stdint.h>
#include <stdio.h>
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

Inventory* getRandomInventory() {
    Inventory* inv = (Inventory*)malloc(sizeof(Inventory));
    for (int i = 0; i < INVENTORY_SPACE; i++) {
        inv->tiles[i] = getRandomTile();
    }
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
    copyBoard(copiedBoardLayer, board);
    for (int index = 0; index < BOARD_WIDTH * BOARD_HEIGTH; index++) {
        int x = index % BOARD_WIDTH;
        int y = index / BOARD_WIDTH;
        
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
    recBestMove(threadData->inv, threadData->board, INVENTORY_SPACE,  threadData->bestMove, threadData->currentMove);
    pthread_exit(NULL);
}

Move getBestMove(Inventory* inv, RowType* board) {
    Move* bestMoves[6] = { NULL, NULL, NULL, NULL, NULL, NULL };
    ThreadData* data[6]  = { NULL, NULL, NULL, NULL, NULL, NULL };
    My_pthread_t tid[6];

    Inventory* perms = getInventoryPermutations(inv);
    //Preprocess ThreadData
    for(uint8_t i = 0; i < 6; i++){
        Inventory permInv = perms[i];
        Move* curMove = (Move*)malloc(sizeof(Move));
        Move* bestMove = (Move*)malloc(sizeof(Move)); 
        ThreadData* tData = (ThreadData*)malloc(sizeof(ThreadData));

        curMove->isPlaceable = 0;
        curMove->points = 0;
        bestMove->isPlaceable = 0;
        bestMove->points = 0;

        tData->inv = &permInv;
        tData->board = board;
        tData->bestMove = bestMove;
        tData->currentMove = curMove;

        bestMoves[i] = bestMove;
        data[i] = tData;
    }

    //Permutation Loop
    for(uint8_t i = 0; i < 6; i++){
        pthread_create(&tid[i], NULL, recBestMoveStarter, data[i]);
        //recBestMove(data[i]->inv, board, INVENTORY_SPACE, data[i]->bestMove, data[i]->currentMove);
    }

    for(uint8_t i = 0; i < 6; i++){
        pthread_join(tid[i], NULL);
    }

    Move realbestMove = { .isPlaceable = 0, .points = 0};
    RewardType bestPoints = 0;
    for(uint8_t i = 0; i < 6; i++){
        if (bestMoves[i]->points > bestPoints) {
            bestPoints = bestMoves[i]->points;
            realbestMove.isPlaceable = bestMoves[i]->isPlaceable;
            realbestMove.points = bestMoves[i]->points;
            for(uint8_t j = 0; j < 3; j++){
                realbestMove.moves[j] = bestMoves[i]->moves[j];
            }
        }
    }

    return realbestMove;
}
