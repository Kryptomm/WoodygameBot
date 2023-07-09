#ifndef BOARD_H
#define BOARD_H

#include "defines.h"

RowType (*getBoard());

void printBoard(void);

uint8_t getBlockOnBoard(uint8_t x, uint8_t y);
void setBlockOnBoard(uint8_t x, uint8_t y, uint8_t num);



#endif  // BOARD_H