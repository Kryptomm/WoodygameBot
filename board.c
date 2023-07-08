#include "board.h"
#include "defines.h"
#include <stdint.h>
#include <stdio.h>

RowType board[BOARD_HEIGTH];

RowType (*getBoard()) {
    return board;
}

void printBoard(void){
    for(uint8_t y = 0; y < BOARD_HEIGTH; y++){
        for(uint8_t x = 0; x < BOARD_WIDTH; x++){
            uint8_t block = getBlockOnBoard(x,y);
            if (block){
                printf(ANSI_COLOR_GREEN "%d " ANSI_COLOR_RESET, block);
            }
            else {
                printf(ANSI_COLOR_RED "%d " ANSI_COLOR_RESET, block);
            }
        }
        printf("\n");
    }
}

uint8_t getBlockOnBoard(uint8_t x, uint8_t y) {
    return (board[y] >> (15 - x)) & 1;
}

void setBlockOnBoard(uint8_t x, uint8_t y, uint8_t num){
    if(num) {
        board[y] |= (1 << (15-x));
    }
    else {
        board[y] &= ~(1 << (15-x));
    }
}