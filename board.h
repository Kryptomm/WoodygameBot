#ifndef BOARD_H
#define BOARD_H

#include "defines.h"
#include "tiles.h"

void printBoard(RowType* board);

uint8_t isPlaceable(Tile* tile, uint8_t x, uint8_t y, RowType* board);
uint8_t placeTileOnBoard(Tile* tile, uint8_t x, uint8_t y, RowType* board);

uint8_t cleanFullRows(Tile* tile, uint8_t x, uint8_t y, RowType* board);

uint8_t getBlockOnBoard(RowType* board, uint8_t x, uint8_t y);
void setBlockOnBoard(RowType* board, uint8_t x, uint8_t y, uint8_t num);

void copyBoard(RowType* destination, RowType* source);
void pasteBoard(RowType* destination, RowType* source);
void resetBoard(RowType* board);

#endif  // BOARD_H
