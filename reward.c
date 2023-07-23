#include "defines.h"
#include "reward.h"
#include "board.h"
#include "tiles.h"
#include "board.h"

#include <stdio.h>
#include <stdint.h>

int freeSpraceMult = 10;
int edgesMult = 5;
int singleblockMult = 0;
int blocksFittingMult = 1;
int twoPieceSupportMult = 5;

void setMults(int arr[]) {
    freeSpraceMult = arr[0];
    edgesMult = arr[1];
    singleblockMult = arr[2];
    blocksFittingMult = arr[3];
    twoPieceSupportMult = arr[4];
}

RewardType twoPieceSupport(RowType* board) {
    RewardType points = 0;
    RewardType possiblePoints = 0;

    int tile_amount = getTilesAmount();

    for(int i = 0; i < tile_amount; i++){
        if(NOT_VALID_TILE(i)) continue;
        Tile tile1 = getTile(i);
        
        for(int j = 0; j < tile_amount; j++){
            if(NOT_VALID_TILE(j)) continue;
            Tile tile2 = getTile(j);

            possiblePoints += (tile1.height * tile1.width) + (tile2.width * tile2.height);
            
            uint8_t tileNotPossible = 1;
            RowType* copiedBoard[BOARD_HEIGTH];
            copyBoard(copiedBoard, board);
            for (int index1 = 0; index1 < BOARD_WIDTH * BOARD_HEIGTH && tileNotPossible; index1++) {
                int x1 = index1 % BOARD_WIDTH;
                int y1 = index1 / BOARD_WIDTH;

                if (!placeTileOnBoard(&tile1, x1, y1, copiedBoard)) continue;
                cleanFullRows(&tile1, x1, y1, copiedBoard);

                for (int index2 = 0; index2 < BOARD_WIDTH * BOARD_HEIGTH && tileNotPossible; index2++) {
                    int x2 = index2 % BOARD_WIDTH;
                    int y2 = index2 / BOARD_WIDTH;

                    if (!placeTileOnBoard(&tile1, x2, y2, copiedBoard)) continue;
                    tileNotPossible = 0;
                    points += (tile1.height * tile1.width) + (tile2.width * tile2.height);
                }
            }
        }
    }
    return (points * REWARD_SCALE_MULTIPLIER) / possiblePoints;
}

RewardType singleBlocksFitting(RowType* board) {
    RewardType points = 0;
    RewardType possiblePoints = 0;
    int tile_amount = getTilesAmount();
    for(int t = 0; t < tile_amount; t++){
        uint8_t skipTile = 0;
        Tile tile = getTile(t);
        possiblePoints += tile.points;
        for(uint8_t y = 0; y < BOARD_HEIGTH && !skipTile; y++){
            for(uint8_t x = 0; x < BOARD_WIDTH && !skipTile; x++){
                if (isPlaceable(&tile, x, y, board)){
                    skipTile = 1;
                    points += tile.points;
                }
            }
        }
    }
    return (points * REWARD_SCALE_MULTIPLIER) / possiblePoints;
}

RewardType singleBlockObs(RowType* board) {
    uint16_t singleBlocks = 0;
    uint16_t totalSingleBlocks = ((BOARD_HEIGTH - 1) * (BOARD_HEIGTH - 1)) / 2;
    for(uint8_t y = 1; y < BOARD_HEIGTH - 1; y++){
        for(uint8_t x = 1; x < BOARD_WIDTH - 1; x++){
            uint8_t block = getBlockOnBoard(board, x, y);
            uint8_t rightBlock = getBlockOnBoard(board, x + 1, y);
            uint8_t belowBlock = getBlockOnBoard(board, x, y + 1);
            uint8_t leftBlock = getBlockOnBoard(board, x - 1, y);
            uint8_t upBlock = getBlockOnBoard(board, x, y - 1);

            if(block && !rightBlock && !belowBlock && !leftBlock && !upBlock) singleBlocks++;
        }
    }
    return ((totalSingleBlocks - singleBlocks) * REWARD_SCALE_MULTIPLIER) / totalSingleBlocks;
}

RewardType edgesReward(RowType* board) {
    uint16_t edges = 0;
    uint16_t totalEdges = BOARD_HEIGTH * (BOARD_WIDTH - 1) + BOARD_WIDTH * (BOARD_HEIGTH - 1);
    for(uint8_t y = 0; y < BOARD_HEIGTH; y++){
        for(uint8_t x = 0; x < BOARD_WIDTH; x++){
            uint8_t block = getBlockOnBoard(board, x, y);
            uint8_t rightBlock = getBlockOnBoard(board, x + 1, y);
            uint8_t belowBlock = getBlockOnBoard(board, x, y + 1);

            if(block != rightBlock && rightBlock != 2) edges++;
            if(block != belowBlock && belowBlock != 2) edges++;
        }
    }
    return ((totalEdges - edges) * REWARD_SCALE_MULTIPLIER) / totalEdges;
}

RewardType freeSpaceReward(RowType* board) {
    RewardType freeSpace = BOARD_HEIGTH * BOARD_WIDTH;
    for(uint8_t y = 0; y < BOARD_HEIGTH; y++){
        RowType row = board[y];
        while(row != 0){
            freeSpace -= row & 1;
            row >>= 1;
        }
    }
    return (freeSpace * REWARD_SCALE_MULTIPLIER) / (BOARD_HEIGTH * BOARD_WIDTH);
}

RewardType judgeBoard(RowType* board) {
    RewardType reward = 0;

    reward += freeSpraceMult * freeSpaceReward(board);
    reward += edgesMult * edgesReward(board);
    reward += singleblockMult * singleBlockObs(board);
    reward += blocksFittingMult * singleBlocksFitting(board);
    reward += twoPieceSupportMult * twoPieceSupport(board);

    return reward;
}