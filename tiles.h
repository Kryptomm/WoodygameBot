#ifndef TILES_H
#define TILES_H

#include "defines.h"

typedef struct
{
    TileType grid[MAX_TILE_HEIGHT];
    uint8_t height;
    uint8_t width;
    uint8_t points;
} Tile;

void initTiles(void);
Tile getRandomTile(void);
void printTile(Tile* tile);

extern Tile emptyTile;
extern Tile oneBlock;
extern Tile twoBlockVertical;
extern Tile threeBlockVertical;
extern Tile fourBlockVertical;
extern Tile fiveBlockVertical;
extern Tile twoBlockHorizontal;
extern Tile threeBlockHorizontal;
extern Tile fourBlockHorizontal;
extern Tile fiveBlockHorizontal;
extern Tile bottomLeftBigL;
extern Tile bottomRightBigL;
extern Tile topLeftBigL;
extern Tile topRightBigL;
extern Tile smallSquare;
extern Tile bigSquare;
extern Tile bottomLeftSmallL;
extern Tile bottomRightSmallL;
extern Tile topLeftSmallL;
extern Tile topRightSmallL;

#endif 
