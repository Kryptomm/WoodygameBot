#include "tiles.h"
#include <stdint.h>
#include <time.h>

Tile tiles[41];

Tile emptyTile = {
    .id = 0,
    .grid = {},
    .height = 0,
    .width = 0,
    .points = 0
};

Tile oneBlock = {
    .id = 1,
    .grid = {0b1},
    .height = 1,
    .width = 1,
    .points = 1
};

Tile twoBlockVertical = {
    .id = 2,
    .grid = {0b1,0b1},
    .height = 2,
    .width = 1,
    .points = 2
};

Tile threeBlockVertical = {
    .id = 3,
    .grid = {0b1,0b1,0b1},
    .height = 3,
    .width = 1,
    .points = 3
};

Tile fourBlockVertical = {
    .id = 4,
    .grid = {0b1,0b1,0b1,0b1},
    .height = 4,
    .width = 1,
    .points = 4
};

Tile fiveBlockVertical = {
    .id = 5,
    .grid = {0b1,0b1,0b1,0b1,0b1},
    .height = 5,
    .width = 1,
    .points = 5
};

Tile twoBlockHorizontal = {
    .id = 6,
    .grid = {0b11},
    .height = 1,
    .width = 2,
    .points = 2
};

Tile threeBlockHorizontal = {
    .id = 7,
    .grid = {0b111},
    .height = 1,
    .width = 3,
    .points = 3
};

Tile fourBlockHorizontal = {
    .id = 8,
    .grid = {0b1111},
    .height = 1,
    .width = 4,
    .points = 4
};

Tile fiveBlockHorizontal = {
    .id = 9,
    .grid = {0b11111},
    .height = 1,
    .width = 5,
    .points = 5
};

Tile bottomLeftBigL = {
    .id = 10,
    .grid = {0b100, 0b100, 0b111},
    .height = 3,
    .width = 3,
    .points = 5
};

Tile bottomRightBigL = {
    .id = 11,
    .grid = {0b001, 0b001, 0b111},
    .height = 3,
    .width = 3,
    .points = 5
};

Tile topLeftBigL = {
    .id = 12,
    .grid = {0b111, 0b100, 0b100},
    .height = 3,
    .width = 3,
    .points = 5
};

Tile topRightBigL = {
    .id = 13,
    .grid = {0b111, 0b001, 0b001},
    .height = 3,
    .width = 3,
    .points = 5
};

Tile smallSquare = {
    .id = 14,
    .grid = {0b11,0b11},
    .height = 2,
    .width = 2 ,
    .points = 4
};

Tile bigSquare = {
    .id = 15,
    .grid = {0b111, 0b111, 0b111},
    .height = 3,
    .width = 3,
    .points = 9
};

Tile bottomLeftSmallL = {
    .id = 16,
    .grid = {0b10, 0b11},
    .height = 2,
    .width = 2,
    .points = 3
};

Tile bottomRightSmallL = {
    .id = 17,
    .grid = {0b01, 0b11},
    .height = 2,
    .width = 2,
    .points = 3
};

Tile topLeftSmallL = {
    .id = 18,
    .grid = {0b11, 0b10},
    .height = 2,
    .width = 2,
    .points = 3
};

Tile topRightSmallL = {
    .id = 19,
    .grid = {0b11, 0b01},
    .height = 2,
    .width = 2,
    .points = 3
};

Tile upTriangle = {
    .id = 20,
    .grid = {0b010, 0b111},
    .height = 2,
    .width = 3,
    .points = 4
};

Tile downTriangle = {
    .id = 21,
    .grid = {0b111, 0b010},
    .height = 2,
    .width = 3,
    .points = 4
};

Tile leftTriangle = {
    .id = 22,
    .grid = {0b01, 0b11, 0b01},
    .height = 3,
    .width = 2,
    .points = 4
};

Tile rightTriangle = {
    .id = 23,
    .grid = {0b10, 0b11, 0b10},
    .height = 3,
    .width = 2,
    .points = 4
};

Tile normLdown = {
    .id = 24,
    .grid = {0b10, 0b10, 0b11},
    .height = 3,
    .width = 2,
    .points = 4
};

Tile normLup = {
    .id = 25,
    .grid = {0b11, 0b01, 0b01},
    .height = 3,
    .width = 2,
    .points = 4
};

Tile normLleft = {
    .id = 26,
    .grid = {0b111, 0b100},
    .height = 2,
    .width = 3,
    .points = 4
};

Tile normLright = {
    .id = 27,
    .grid = {0b001, 0b111},
    .height = 2,
    .width = 3,
    .points = 4
};

Tile invLdown = {
    .id = 28,
    .grid = {0b01, 0b01, 0b11},
    .height = 3,
    .width = 2,
    .points = 4
};

Tile invLup = {
    .id = 29,
    .grid = {0b11, 0b10, 0b10},
    .height = 3,
    .width = 2,
    .points = 4
};

Tile invLleft = {
    .id = 30,
    .grid = {0b100, 0b111},
    .height = 2,
    .width = 3,
    .points = 4
};

Tile invLright = {
    .id = 31,
    .grid = {0b111, 0b001},
    .height = 2,
    .width = 3,
    .points = 4
};

Tile normSStand = {
    .id = 32,
    .grid = {0b011, 0b110},
    .height = 2,
    .width = 3,
    .points = 4
};

Tile normSSide = {
    .id = 33,
    .grid = {0b10, 0b11, 0b01},
    .height = 3,
    .width = 2,
    .points = 4
};

Tile invSStand = {
    .id = 34,
    .grid = {0b110, 0b011},
    .height = 2,
    .width = 3,
    .points = 4
};

Tile invSSide = {
    .id = 35,
    .grid = {0b01, 0b11, 0b10},
    .height = 3,
    .width = 2,
    .points = 4
};

Tile twoTimesThreeRecStand = {
    .id = 36,
    .grid = {0b11, 0b11, 0b11},
    .height = 3,
    .width = 2,
    .points = 6
};

Tile twoTimesThreeRecSide = {
    .id = 37,
    .grid = {0b111, 0b111},
    .height = 2,
    .width = 3,
    .points = 6
};

Tile bridgeHoleUp = {
    .id = 38,
    .grid = {0b101, 0b111},
    .height = 2,
    .width = 3,
    .points = 5
};

Tile bridgeHoleDown = {
    .id = 39,
    .grid = {0b111, 0b101},
    .height = 2,
    .width = 3,
    .points = 5
};

Tile bridgeHoleLeft = {
    .id = 40,
    .grid = {0b11, 0b01, 0b11},
    .height = 3,
    .width = 2,
    .points = 5
};

Tile bridgeHoleRight = {
    .id = 41,
    .grid = {0b11, 0b10, 0b11},
    .height = 3,
    .width = 2,
    .points = 5
};

Tile longLUp = {
    .id = 42,
    .grid = {0b10, 0b10, 0b10, 0b11},
    .height = 4,
    .width = 2,
    .points = 5
};

void initTiles() {
    tiles[0] = emptyTile;
    tiles[1] = oneBlock;
    tiles[2] = twoBlockVertical;
    tiles[3] = threeBlockVertical;
    tiles[4] = fourBlockVertical;
    tiles[5] = fiveBlockVertical;
    tiles[6] = twoBlockHorizontal;
    tiles[7] = threeBlockHorizontal;
    tiles[8] = fourBlockHorizontal;
    tiles[9] = fiveBlockHorizontal;
    tiles[10] = bottomLeftBigL;
    tiles[11] = bottomRightBigL;
    tiles[12] = topLeftBigL;
    tiles[13] = topRightBigL;
    tiles[14] = smallSquare;
    tiles[15] = bigSquare;
    tiles[16] = bottomLeftSmallL;
    tiles[17] = bottomRightSmallL;
    tiles[18] = topLeftSmallL;
    tiles[19] = topRightSmallL;
    tiles[20] = upTriangle;
    tiles[21] = downTriangle;
    tiles[22] = leftTriangle;
    tiles[23] = rightTriangle;
    tiles[24] = normLdown;
    tiles[25] = normLup;
    tiles[26] = normLleft;
    tiles[27] = normLright;
    tiles[28] = invLdown;
    tiles[29] = invLup;
    tiles[30] = invLleft;
    tiles[31] = invLright;
    tiles[32] = normSStand;
    tiles[33] = normSSide;
    tiles[34] = invSStand;
    tiles[35] = invSSide;
    tiles[36] = twoTimesThreeRecStand;
    tiles[37] = twoTimesThreeRecSide;
    tiles[38] = bridgeHoleUp;
    tiles[39] = bridgeHoleDown;
    tiles[40] = bridgeHoleLeft;
    tiles[41] = bridgeHoleRight;
}

Tile getRandomTile() {
    size_t numTiles = sizeof(tiles) / sizeof(tiles[0]);
    size_t randomIndex;
    uint8_t isValidTile;

    int excludedList[] = { 0 };
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

Tile getTile(uint16_t num){
    return tiles[num];
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