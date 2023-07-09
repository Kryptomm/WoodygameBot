#ifndef BOARD_H
#define BOARD_H

#include "defines.h"
#include "tiles.h"

void printBoard(void);

uint8_t isPlaceable(Tile* tile, uint8_t x, uint8_t y);
uint8_t placeTileOnBoard(Tile* tile, uint8_t x, uint8_t y);

uint8_t cleanFullRows(Tile* tile, uint8_t x, uint8_t y);

uint8_t getBlockOnBoard(uint8_t x, uint8_t y);
void setBlockOnBoard(uint8_t x, uint8_t y, uint8_t num);

void copyBoard(RowType* destination[]);
void pasteBoard(RowType* source[]);

extern RowType board[BOARD_HEIGTH];

#endif  // BOARD_H
