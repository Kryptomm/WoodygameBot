#ifndef TILES_H
#define TILES_H

#include "defines.h"

typedef struct
{
    TileType grid[MAX_TILE_HEIGHT];
    uint8_t height;
    uint8_t width;
} Tile;

extern Tile oneBlock;
extern Tile twoBlockVertical;
extern Tile threeBlockVertical;
extern Tile fourBlockVertical;
extern Tile fiveBlockVertical;
extern Tile twoBlockHorizontal;
extern Tile threeBlockHorizontal;
extern Tile fourBlockHorizontal;
extern Tile fiveBlockHorizontal;

#endif 
