#include "board.h"
#include "defines.h"
#include <stdint.h>
#include <stdio.h>

RowType board[BOARD_HEIGTH] = {0};

void printBoard(void){
    for(uint8_t y = 0; y < BOARD_HEIGTH; y++){
        printf("%d\t",board[y]);
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

uint8_t isPlaceable(Tile* tile, uint8_t x, uint8_t y) {
    if (tile->width + x - 1 >= BOARD_WIDTH) return 0;
    if (tile->height + y - 1 >= BOARD_HEIGTH) return 0;

    for (uint8_t i = 0; i < tile->height; i++) {
        RowType boardRow = board[y + i] >> (16 - x - tile->width);
        if (tile->grid[i] & boardRow) return 0;
    }
    return 1;
}

void placeTileOnBoard(Tile* tile, uint8_t x, uint8_t y){
    for (uint8_t i = 0; i < tile->height; i++) {
        board[y + i] |= (tile->grid[i] << (16 - x  - tile->width));
    }
}

//Gets a Single Block on Board
uint8_t getBlockOnBoard(uint8_t x, uint8_t y) {
    return (board[y] >> (15 - x)) & 1;
}

//Places a single Block on Board
void setBlockOnBoard(uint8_t x, uint8_t y, uint8_t num){
    if(num) {
        board[y] |= (1 << (15-x));
    }
    else {
        board[y] &= ~(1 << (15-x));
    }
}