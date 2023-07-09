#include <stdint.h>
#include <stdlib.h>
#include "defines.h"
#include <stddef.h>
#include "move.h"
#include "board.h"
#include "reward.h"

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

    return perms;
}

Inventory getRandomInventory() {
    Inventory inv = {
        .tiles = {getRandomTile(), getRandomTile(), getRandomTile()}
    };
    return inv;
}

Move getBestMove(Inventory inv) {
    Move bestMove = {
        .moves = { NULL, NULL, NULL },
        .isPlaceable = 0
    };

    RewardType bestPoint = 0;
    Inventory* perms = getInventoryPermutations(inv);

    //Permutation Loop
    for(uint8_t i = 0; i < 6; i++){
        Inventory permInv = perms[i];

        //START ERSTE ITERATION
        for(int index0 = 0; index0 < BOARD_WIDTH * BOARD_HEIGTH; index0++){
            int x0 = index0 % BOARD_WIDTH;
            int y0 = index0 / BOARD_WIDTH;

            //Before Iteration of Placement
            RowType* copiedBoardLayer0[BOARD_HEIGTH];
            copyBoard(copiedBoardLayer0);

            //Placement
            Tile firstTile = permInv.tiles[0];
            if (!placeTileOnBoard(&firstTile, x0, y0)) continue;
            cleanFullRows(&firstTile, x0, y0);

            //START ZWEITE ITERATION
            for(int index1 = 0; index1 < BOARD_WIDTH * BOARD_HEIGTH; index1++){
                int x1 = index1 % BOARD_WIDTH;
                int y1 = index1 / BOARD_WIDTH;

                RowType* copiedBoardLayer1[BOARD_HEIGTH];
                copyBoard(copiedBoardLayer1);

                Tile secondTile = permInv.tiles[1];
                if (!placeTileOnBoard(&secondTile, x1, y1)) continue;
                cleanFullRows(&secondTile, x1, y1);

                //START DRITTE ITERATION
                for(int index2 = 0; index2 < BOARD_WIDTH * BOARD_HEIGTH; index2++){
                    int x2 = index2 % BOARD_WIDTH;
                    int y2 = index2 / BOARD_WIDTH;

                    RowType* copiedBoardLayer2[BOARD_HEIGTH];
                    copyBoard(copiedBoardLayer2);

                    Tile thirdTile = permInv.tiles[2];
                    if (!placeTileOnBoard(&thirdTile, x2, y2)) continue;
                    cleanFullRows(&thirdTile, x2, y2);

                    //HIER BEST MOVE EVALUATEN
                    RewardType boardScore = judgeBoard(board);
                    if(boardScore > bestPoint){
                        bestPoint = boardScore;
                        SingleMove move1 = { .tile = firstTile, .x_position = x0, .y_position = y0 };
                        SingleMove move2 = { .tile = secondTile, .x_position = x1, .y_position = y1 };
                        SingleMove move3 = { .tile = thirdTile, .x_position = x2, .y_position = y2 };

                        bestMove.moves[0] = move1;
                        bestMove.moves[1] = move2;
                        bestMove.moves[2] = move3;

                        bestMove.isPlaceable = 1;
                    }

                    pasteBoard(copiedBoardLayer2);
                }
                //ENDE DRITTE ITERATION

                pasteBoard(copiedBoardLayer1);
            }
            //ENDE ZWEITE ITERATION

            //After an Iteration of Placement
            pasteBoard(copiedBoardLayer0);
        }
        //ENDE ERSTE ITERATION
    }

    return bestMove;
}
