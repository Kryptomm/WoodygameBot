#include "board.h"
#include "defines.h"
#include <stdint.h>
#include <stdio.h>

RowType board[BOARD_HEIGTH] = {0};

void printBoard(void){
    printf("#################\n");
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

uint8_t isPlaceable(Tile* tile, uint8_t x, uint8_t y) {
    if (tile->width + x - 1 >= BOARD_WIDTH) return 0;
    if (tile->height + y - 1 >= BOARD_HEIGTH) return 0;

    for (uint8_t i = 0; i < tile->height; i++) {
        RowType boardRow = board[y + i] >> (16 - x - tile->width);
        if (tile->grid[i] & boardRow) return 0;
    }
    return 1;
}

uint8_t placeTileOnBoard(Tile* tile, uint8_t x, uint8_t y){
    if (!isPlaceable(tile,x,y)) return 0;
    for (uint8_t i = 0; i < tile->height; i++) {
        board[y + i] |= (tile->grid[i] << (16 - x  - tile->width));
    }
    return 1;
}

//Cleans Rows and Columns based on the last placed tile and their position
//Returns the number of Columns and Rows cleared.
uint8_t cleanFullRows(Tile* tile, uint8_t x, uint8_t y) {
    uint8_t clearedRows = 0;
    uint8_t rowsToClear = 0;
    uint8_t columnsToClear = 0;

    //Rows
    for(uint8_t i = 0; i < tile->height; i++){
        rowsToClear <<= 1;
        if(board[y + i] == (uint16_t)(0xFFFF << (16 - BOARD_WIDTH))){
            rowsToClear |= 1;
            clearedRows++;
        }
    }

    //Columns
    for(uint8_t i = 0; i < tile->width; i++){
        columnsToClear <<= 1;
        uint8_t clearColumn = 1;
        for(uint8_t j = 0; j < BOARD_HEIGTH; j++){
            if(getBlockOnBoard(i + x, j) == 0){
                clearColumn = 0;
            }
        }
        if(clearColumn){
            columnsToClear |= 1;
            clearedRows++;
        }
    }

    //Clean Rows
    for(int8_t i = tile->height - 1; i >= 0; i--){
        if(rowsToClear & 1){
            board[y + i] = 0;
        }
        rowsToClear >>= 1;
    }
    
    //Clean Columns
    for(int8_t i = tile->width - 1; i >= 0; i--){
        if(columnsToClear & 1){
            for(uint8_t j = 0; j < BOARD_HEIGTH; j++){
                setBlockOnBoard(x + i, j, 0);
            }
        }
        columnsToClear >>= 1;
    }
    return clearedRows;
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

void copyBoard(RowType* destination[]) {
    for (int i = 0; i < BOARD_HEIGTH; i++) {
        destination[i] = board[i];
    }
}

void pasteBoard(RowType* source[]){
    for (int i = 0; i < BOARD_HEIGTH; i++) {
        board[i] = source[i];
    }
}

void resetBoard(){
    for(uint8_t y = 0; y < BOARD_HEIGTH; y++){
        board[y] = 0;
    }
}