#include "tiles.h"
#include <stdint.h>

Tile tiles[10];

Tile oneBlock = {
    .grid = {0b1},
    .height = 1,
    .width = 1
};

Tile twoBlockVertical = {
    .grid = {0b1,0b1},
    .height = 2,
    .width = 1
};

Tile threeBlockVertical = {
    .grid = {0b1,0b1,0b1},
    .height = 3,
    .width = 1
};

Tile fourBlockVertical = {
    .grid = {0b1,0b1,0b1,0b1},
    .height = 4,
    .width = 1
};

Tile fiveBlockVertical = {
    .grid = {0b1,0b1,0b1,0b1,0b1},
    .height = 5,
    .width = 1
};

Tile twoBlockHorizontal = {
    .grid = {0b11},
    .height = 1,
    .width = 2
};

Tile threeBlockHorizontal = {
    .grid = {0b111},
    .height = 1,
    .width = 3
};

Tile fourBlockHorizontal = {
    .grid = {0b1111},
    .height = 1,
    .width = 4
};

Tile fiveBlockHorizontal = {
    .grid = {0b11111},
    .height = 1,
    .width = 5
};