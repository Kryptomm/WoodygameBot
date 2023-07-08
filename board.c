#include "board.h"
#include "defines.h"
#include <stdint.h>

RowType board[BOARD_HEIGTH][BOARD_WIDTH];

RowType (*getBoard())[BOARD_WIDTH] {
    return board;
}

void printBoard(void){
    for(uint8_t i = 0; i < BOARD_HEIGTH; i++){
        for(uint8_t j = 0; j < BOARD_WIDTH; j++){
            printf("%hu", board[i][j]);
        }
        printf("\n");
    }
}