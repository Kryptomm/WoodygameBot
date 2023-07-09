#include "tiles.h"
#include <stdint.h>

Tile tiles[10];

Tile oneBlock = {
    .tile = {0b1},
    .heigth = 1,
    .width = 1
}

Tile twoBlockVertical = {
    .tile = {0b1,
            0b1},
    .heigth = 2,
    .width = 1
}

Tile threeBlockVertical = {
    .tile = {0b1,
            0b1,
            0b1},
    .heigth = 3,
    .width = 1
}

Tile fourBlockVertical = {
    .tile = {0b1,
            0b1,
            0b1,
            0b1},
    .heigth = 4,
    .width = 1
}

Tile fiveBlockVertical = {
    .tile = {0b1,
            0b1,
            0b1,
            0b1,
            0b1},
    .heigth = 5,
    .width = 1
}