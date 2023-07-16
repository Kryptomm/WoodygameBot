#include "defines.h"
#include "reward.h"
#include "board.h"
#include "tiles.h"
#include "board.h"

#include <stdio.h>
#include <stdint.h>

RewardType blocksFitting(RowType* board){
    RewardType points = 0;
    int tile_amount = getTilesAmount();
    for(int t = 0; t < tile_amount; t++){
        uint8_t skipTile = 0;
        for(uint8_t y = 0; y < BOARD_HEIGTH && !skipTile; y++){
            for(uint8_t x = 0; x < BOARD_WIDTH && !skipTile; x++){
                Tile tile = getTile(t);
                if (isPlaceable(&tile, x, y)){
                    skipTile = 1;
                    points = tile.points;
                }
            }
        }
    }
    return points;
}

RewardType singleBlockObs(RowType* board){
    uint16_t singleBlocks = 0;
    for(uint8_t y = 1; y < BOARD_HEIGTH - 1; y++){
        for(uint8_t x = 1; x < BOARD_WIDTH - 1; x++){
            uint8_t block = getBlockOnBoard(x, y);
            uint8_t rightBlock = getBlockOnBoard(x + 1, y);
            uint8_t belowBlock = getBlockOnBoard(x, y + 1);
            uint8_t leftBlock = getBlockOnBoard(x - 1, y);
            uint8_t upBlock = getBlockOnBoard(x, y - 1);

            if(block && !rightBlock && !belowBlock && !leftBlock && !upBlock) singleBlocks++;
        }
    }
    return -singleBlocks;
}

RewardType edgesReward(RowType* board){
    uint16_t edges = 0;
    for(uint8_t y = 0; y < BOARD_HEIGTH; y++){
        for(uint8_t x = 0; x < BOARD_WIDTH; x++){
            uint8_t block = getBlockOnBoard(x, y);
            uint8_t rightBlock = getBlockOnBoard(x + 1, y);
            uint8_t belowBlock = getBlockOnBoard(x, y + 1);

            if(block != rightBlock && rightBlock != 2) edges++;
            if(block != belowBlock && belowBlock != 2) edges++;
        }
    }
    return ((BOARD_WIDTH + 1) * BOARD_WIDTH + (BOARD_HEIGTH + 1) * BOARD_WIDTH) - edges;
}

RewardType freeSpaceReward(RowType* board){
    RewardType reward = BOARD_HEIGTH * BOARD_WIDTH;
    for(uint8_t y = 0; y < BOARD_HEIGTH; y++){
        RowType row = board[y];
        while(row != 0){
            reward -= row & 1;
            row >>= 1;
        }
    }
    return reward;
}

RewardType judgeBoard(RowType* board){
    RewardType reward = 0;

    reward += 10 * freeSpaceReward(board);
    reward += edgesReward(board);
    reward += singleBlockObs(board);
    reward += 2 * blocksFitting(board);

    return reward;
}