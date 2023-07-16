#ifndef TILES_H
#define TILES_H

#include "defines.h"

typedef struct
{
    TileType grid[MAX_TILE_HEIGHT];
    uint8_t height;
    uint8_t width;
    uint8_t points;
    uint8_t id;
} Tile;

int getTilesAmount();
Tile getRandomTile(void);
void printTile(Tile* tile);
Tile getTile(uint16_t num);

#endif 
