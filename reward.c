#include "defines.h"
#include "reward.h"

#include <stdio.h>
#include <stdint.h>

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

    reward += freeSpaceReward(board);

    return reward;
}