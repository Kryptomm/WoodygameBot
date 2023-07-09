#include "tiles.h"
#include <stdint.h>
#include <time.h>

Tile tiles[19];

Tile emptyTile = {
    .grid = {},
    .height = 0,
    .width = 0,
    .points = 0
};

Tile oneBlock = {
    .grid = {0b1},
    .height = 1,
    .width = 1,
    .points = 1
};

Tile twoBlockVertical = {
    .grid = {0b1,0b1},
    .height = 2,
    .width = 1,
    .points = 2
};

Tile threeBlockVertical = {
    .grid = {0b1,0b1,0b1},
    .height = 3,
    .width = 1,
    .points = 3
};

Tile fourBlockVertical = {
    .grid = {0b1,0b1,0b1,0b1},
    .height = 4,
    .width = 1,
    .points = 4
};

Tile fiveBlockVertical = {
    .grid = {0b1,0b1,0b1,0b1,0b1},
    .height = 5,
    .width = 1,
    .points = 5
};

Tile twoBlockHorizontal = {
    .grid = {0b11},
    .height = 1,
    .width = 2,
    .points = 2
};

Tile threeBlockHorizontal = {
    .grid = {0b111},
    .height = 1,
    .width = 3,
    .points = 3
};

Tile fourBlockHorizontal = {
    .grid = {0b1111},
    .height = 1,
    .width = 4,
    .points = 4
};

Tile fiveBlockHorizontal = {
    .grid = {0b11111},
    .height = 1,
    .width = 5,
    .points = 5
};

Tile bottomLeftBigL = {
    .grid = {0b100, 0b100, 0b111},
    .height = 3,
    .width = 3,
    .points = 5
};

Tile bottomRightBigL = {
    .grid = {0b001, 0b001, 0b111},
    .height = 3,
    .width = 3,
    .points = 5
};

Tile topLeftBigL = {
    .grid = {0b111, 0b100, 0b100},
    .height = 3,
    .width = 3,
    .points = 5
};

Tile topRightBigL = {
    .grid = {0b111, 0b001, 0b001},
    .height = 3,
    .width = 3,
    .points = 5
};

Tile smallSquare = {
    .grid = {0b11,0b11},
    .height = 2,
    .width = 2 ,
    .points = 4
};

Tile bigSquare = {
    .grid = {0b111, 0b111, 0b111},
    .height = 3,
    .width = 3,
    .points = 9
};

Tile bottomLeftSmallL = {
    .grid = {0b10, 0b11},
    .height = 2,
    .width = 2,
    .points = 3
};

Tile bottomRightSmallL = {
    .grid = {0b01, 0b11},
    .height = 2,
    .width = 2,
    .points = 3
};

Tile topLeftSmallL = {
    .grid = {0b11, 0b10},
    .height = 2,
    .width = 2,
    .points = 3
};

Tile topRightSmallL = {
    .grid = {0b11, 0b01},
    .height = 2,
    .width = 2,
    .points = 3
};

void initTiles() {
    tiles[0] = oneBlock;
    tiles[1] = twoBlockVertical;
    tiles[2] = threeBlockVertical;
    tiles[3] = fourBlockVertical;
    tiles[4] = fiveBlockVertical;
    tiles[5] = twoBlockHorizontal;
    tiles[6] = threeBlockHorizontal;
    tiles[7] = fourBlockHorizontal;
    tiles[8] = fiveBlockHorizontal;
    tiles[9] = bottomLeftBigL;
    tiles[10] = bottomRightBigL;
    tiles[11] = topLeftBigL;
    tiles[12] = topRightBigL;
    tiles[13] = smallSquare;
    tiles[14] = bigSquare;
    tiles[15] = bottomLeftSmallL;
    tiles[16] = bottomRightSmallL;
    tiles[17] = topLeftSmallL;
    tiles[18] = topRightSmallL;
}

Tile getRandomTile() {
    size_t numTiles = sizeof(tiles) / sizeof(tiles[0]);
    size_t randomIndex;
    uint8_t isValidTile;

    int excludedList[] = { };
    size_t numExcluded = sizeof(excludedList) / sizeof(excludedList[0]);

    do {
        randomIndex = rand() % numTiles;

        // Check if the selected number is in the excluded list
        isValidTile = 1;
        for (size_t i = 0; i < numExcluded; i++) {
            if (randomIndex == excludedList[i]) {
                isValidTile = 0;
                break;
            }
        }
    } while (!isValidTile);

    return tiles[randomIndex];
}


void printTile(Tile* tile) {
    printf("\n###\n");
    for(uint8_t y = 0; y < tile->height; y++){
        for(uint8_t x = 0; x < tile->width; x++){
            uint8_t block = (tile->grid[y] >> (tile->width - 1 - x)) & 1;
            if (block){
                printf(ANSI_COLOR_GREEN "%d " ANSI_COLOR_RESET, block);
            }
            else {
                printf(ANSI_COLOR_RED "%d " ANSI_COLOR_RESET, block);
            }
        }
        printf("\n");
    }
}