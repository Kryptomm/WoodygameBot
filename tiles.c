#include "tiles.h"
#include <stdint.h>
#include <time.h>

Tile tiles[41];

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

Tile upTriangle = {
    .grid = {0b010, 0b111},
    .height = 2,
    .width = 3,
    .points = 4
};

Tile downTriangle = {
    .grid = {0b111, 0b010},
    .height = 2,
    .width = 3,
    .points = 4
};

Tile leftTriangle = {
    .grid = {0b01, 0b11, 0b01},
    .height = 3,
    .width = 2,
    .points = 4
};

Tile rightTriangle = {
    .grid = {0b10, 0b11, 0b10},
    .height = 3,
    .width = 2,
    .points = 4
};

Tile normLdown = {
    .grid = {0b10, 0b10, 0b11},
    .height = 3,
    .width = 2,
    .points = 4
};

Tile normLup = {
    .grid = {0b11, 0b01, 0b01},
    .height = 3,
    .width = 2,
    .points = 4
};

Tile normLleft = {
    .grid = {0b111, 0b100},
    .height = 2,
    .width = 3,
    .points = 4
};

Tile normLright = {
    .grid = {0b001, 0b111},
    .height = 2,
    .width = 3,
    .points = 4
};

Tile invLdown = {
    .grid = {0b01, 0b01, 0b11},
    .height = 3,
    .width = 2,
    .points = 4
};

Tile invLup = {
    .grid = {0b11, 0b10, 0b10},
    .height = 3,
    .width = 2,
    .points = 4
};

Tile invLleft = {
    .grid = {0b100, 0b111},
    .height = 2,
    .width = 3,
    .points = 4
};

Tile invLright = {
    .grid = {0b111, 0b001},
    .height = 2,
    .width = 3,
    .points = 4
};

Tile normSStand = {
    .grid = {0b011, 0b110},
    .height = 2,
    .width = 3,
    .points = 4
};

Tile normSSide = {
    .grid = {0b10, 0b11, 0b01},
    .height = 3,
    .width = 2,
    .points = 4
};

Tile invSStand = {
    .grid = {0b110, 0b011},
    .height = 2,
    .width = 3,
    .points = 4
};

Tile invSSide = {
    .grid = {0b01, 0b11, 0b10},
    .height = 3,
    .width = 2,
    .points = 4
};

Tile twoTimesThreeRecStand = {
    .grid = {0b11, 0b11, 0b11},
    .height = 3,
    .width = 2,
    .points = 6
};

Tile twoTimesThreeRecSide = {
    .grid = {0b111, 0b111},
    .height = 2,
    .width = 3,
    .points = 6
};

Tile bridgeHoleUp = {
    .grid = {0b101, 0b111},
    .height = 2,
    .width = 3,
    .points = 5
};

Tile bridgeHoleDown = {
    .grid = {0b111, 0b101},
    .height = 2,
    .width = 3,
    .points = 5
};

Tile bridgeHoleLeft = {
    .grid = {0b11, 0b01, 0b11},
    .height = 3,
    .width = 2,
    .points = 5
};

Tile bridgeHoleRight = {
    .grid = {0b11, 0b10, 0b11},
    .height = 3,
    .width = 2,
    .points = 5
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
    tiles[19] = upTriangle;
    tiles[20] = downTriangle;
    tiles[21] = leftTriangle;
    tiles[22] = rightTriangle;
    tiles[23] = normLdown;
    tiles[24] = normLup;
    tiles[25] = normLleft;
    tiles[26] = normLright;
    tiles[27] = invLdown;
    tiles[28] = invLup;
    tiles[29] = invLleft;
    tiles[30] = invLright;
    tiles[31] = normSStand;
    tiles[32] = normSSide;
    tiles[33] = invSStand;
    tiles[34] = invSSide;
    tiles[35] = twoTimesThreeRecStand;
    tiles[36] = twoTimesThreeRecSide;
    tiles[37] = bridgeHoleUp;
    tiles[38] = bridgeHoleDown;
    tiles[39] = bridgeHoleLeft;
    tiles[40] = bridgeHoleRight;
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