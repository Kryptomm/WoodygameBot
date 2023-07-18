#ifndef _MOVE_H
#define _MOVE_H

#include <stdint.h>
#include "defines.h"
#include "tiles.h"

typedef struct {
    Tile tile;
    uint8_t x_position;
    uint8_t y_position;
} SingleMove;

typedef struct {
    SingleMove moves[INVENTORY_SPACE];
    uint8_t isPlaceable;
    RewardType points;
} Move;

typedef struct {
    Tile tiles[INVENTORY_SPACE];
} Inventory;

Inventory* getRandomInventory(void);
Move getBestMove(Inventory* inv, RowType* board);

#endif
