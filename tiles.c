#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>


#include "tiles.h"

Tile tiles[] = {
    { .id = 0, .grid = {}, .height = 0, .width = 0, .points = 0 },  // emptyTile
    { .id = 1, .grid = {0b1}, .height = 1, .width = 1, .points = 1 },  // oneBlock
    { .id = 2, .grid = {0b1,0b1}, .height = 2, .width = 1, .points = 2 },  // twoBlockVertical
    { .id = 3, .grid = {0b1,0b1,0b1}, .height = 3, .width = 1, .points = 3 },  // threeBlockVertical
    { .id = 4, .grid = {0b1,0b1,0b1,0b1}, .height = 4, .width = 1, .points = 4 },  // fourBlockVertical
    { .id = 5, .grid = {0b1,0b1,0b1,0b1,0b1}, .height = 5, .width = 1, .points = 5 },  // fiveBlockVertical
    { .id = 6, .grid = {0b11}, .height = 1, .width = 2, .points = 2 },  // twoBlockHorizontal
    { .id = 7, .grid = {0b111}, .height = 1, .width = 3, .points = 3 },  // threeBlockHorizontal
    { .id = 8, .grid = {0b1111}, .height = 1, .width = 4, .points = 4 },  // fourBlockHorizontal
    { .id = 9, .grid = {0b11111}, .height = 1, .width = 5, .points = 5 },  // fiveBlockHorizontal
    { .id = 10, .grid = {0b100, 0b100, 0b111}, .height = 3, .width = 3, .points = 5 },  // bottomLeftBigL
    { .id = 11, .grid = {0b001, 0b001, 0b111}, .height = 3, .width = 3, .points = 5 },  // bottomRightBigL
    { .id = 12, .grid = {0b111, 0b100, 0b100}, .height = 3, .width = 3, .points = 5 },  // topLeftBigL
    { .id = 13, .grid = {0b111, 0b001, 0b001}, .height = 3, .width = 3, .points = 5 },  // topRightBigL
    { .id = 14, .grid = {0b11,0b11}, .height = 2, .width = 2 , .points = 4 },  // smallSquare
    { .id = 15, .grid = {0b111, 0b111, 0b111}, .height = 3, .width = 3, .points = 9 },  // bigSquare
    { .id = 16, .grid = {0b10, 0b11}, .height = 2, .width = 2, .points = 3 },  // bottomLeftSmallL
    { .id = 17, .grid = {0b01, 0b11}, .height = 2, .width = 2, .points = 3 },  // bottomRightSmallL
    { .id = 18, .grid = {0b11, 0b10}, .height = 2, .width = 2, .points = 3 },  // topLeftSmallL
    { .id = 19, .grid = {0b11, 0b01}, .height = 2, .width = 2, .points = 3 },  // topRightSmallL
    { .id = 20, .grid = {0b010, 0b111}, .height = 2, .width = 3, .points = 4 },  // upTriangle
    { .id = 21, .grid = {0b111, 0b010}, .height = 2, .width = 3, .points = 4 },  // downTriangle
    { .id = 22, .grid = {0b01, 0b11, 0b01}, .height = 3, .width = 2, .points = 4 },  // leftTriangle
    { .id = 23, .grid = {0b10, 0b11, 0b10}, .height = 3, .width = 2, .points = 4 },  // rightTriangle
    { .id = 24, .grid = {0b10, 0b10, 0b11}, .height = 3, .width = 2, .points = 4 },  // normLdown
    { .id = 25, .grid = {0b11, 0b01, 0b01}, .height = 3, .width = 2, .points = 4 },  // normLup
    { .id = 26, .grid = {0b111, 0b100}, .height = 2, .width = 3, .points = 4 },  // normLleft
    { .id = 27, .grid = {0b001, 0b111}, .height = 2, .width = 3, .points = 4 },  // normLright
    { .id = 28, .grid = {0b01, 0b01, 0b11}, .height = 3, .width = 2, .points = 4 },  // invLdown
    { .id = 29, .grid = {0b11, 0b10, 0b10}, .height = 3, .width = 2, .points = 4 },  // invLup
    { .id = 30, .grid = {0b100, 0b111}, .height = 2, .width = 3, .points = 4 },  // invLleft
    { .id = 31, .grid = {0b111, 0b001}, .height = 2, .width = 3, .points = 4 },  // invLright
    { .id = 32, .grid = {0b011, 0b110}, .height = 2, .width = 3, .points = 4 },  // normSStand
    { .id = 33, .grid = {0b10, 0b11, 0b01}, .height = 3, .width = 2, .points = 4 },  // normSSide
    { .id = 34, .grid = {0b110, 0b011}, .height = 2, .width = 3, .points = 4 },  // invSStand
    { .id = 35, .grid = {0b01, 0b11, 0b10}, .height = 3, .width = 2, .points = 4 },  // invSSide
    { .id = 36, .grid = {0b11, 0b11, 0b11}, .height = 3, .width = 2, .points = 6 },  // twoTimesThreeRecStand
    { .id = 37, .grid = {0b111, 0b111}, .height = 2, .width = 3, .points = 6 },  // twoTimesThreeRecSide
    { .id = 38, .grid = {0b101, 0b111}, .height = 2, .width = 3, .points = 5 },  // bridgeHoleUp
    { .id = 39, .grid = {0b111, 0b101}, .height = 2, .width = 3, .points = 5 },  // bridgeHoleDown
    { .id = 40, .grid = {0b11, 0b01, 0b11}, .height = 3, .width = 2, .points = 5 },  // bridgeHoleLeft
    { .id = 41, .grid = {0b11, 0b10, 0b11}, .height = 3, .width = 2, .points = 5 },  // bridgeHoleRight
    { .id = 42, .grid = {0b10, 0b10, 0b10, 0b11}, .height = 4, .width = 2, .points = 5 },  // longLUp
    { .id = 43, .grid = {0b11, 0b01, 0b01, 0b01}, .height = 4, .width = 2, .points = 5 },  // longLDown
    { .id = 44, .grid = {0b0001, 0b1111}, .height = 2, .width = 4, .points = 5 },  // longLRight
    { .id = 45, .grid = {0b1111, 0b1000}, .height = 2, .width = 4, .points = 5 },  // longLLeft
    { .id = 46, .grid = {0b01, 0b01, 0b01, 0b11}, .height = 4, .width = 2, .points = 5 },  // invlongLUp
    { .id = 47, .grid = {0b11, 0b10, 0b10, 0b10}, .height = 4, .width = 2, .points = 5 },  // invlongLDown
    { .id = 48, .grid = {0b1111, 0b0001}, .height = 2, .width = 4, .points = 5 },  // invlongLRight
    { .id = 49, .grid = {0b1000, 0b1111}, .height = 2, .width = 4, .points = 5 },  // invlongLLeft
    { .id = 50, .grid = {0b010, 0b010, 0b111}, .height = 3, .width = 3, .points = 5 },  // TformUp
    { .id = 51, .grid = {0b111, 0b010, 0b010}, .height = 3, .width = 3, .points = 5 },  // TformDown
    { .id = 52, .grid = {0b001, 0b111, 0b001}, .height = 3, .width = 3, .points = 5 },  // TformLeft
    { .id = 53, .grid = {0b100, 0b111, 0b100}, .height = 3, .width = 3, .points = 5 },  // TformRight
    { .id = 54, .grid = {0b110, 0b010, 0b011}, .height = 3, .width = 3, .points = 5 },  // ZformStand
    { .id = 55, .grid = {0b001, 0b111, 0b100}, .height = 3, .width = 3, .points = 5 },  // ZformSide
    { .id = 56, .grid = {0b011, 0b010, 0b110}, .height = 3, .width = 3, .points = 5 },  // invZformStand
    { .id = 57, .grid = {0b100, 0b111, 0b001}, .height = 3, .width = 3, .points = 5 },  // invZformSide
    { .id = 58, .grid = {0b10, 0b11, 0b11}, .height = 3, .width = 2, .points = 5 },  // smallSquareWithPenisUp
    { .id = 59, .grid = {0b11, 0b11, 0b01}, .height = 3, .width = 2, .points = 5 },  // smallSquareWithPenisDown
    { .id = 60, .grid = {0b011, 0b111}, .height = 2, .width = 3, .points = 5 },  // smallSquareWithPenisLeft
    { .id = 61, .grid = {0b111, 0b110}, .height = 2, .width = 3, .points = 5 },  // smallSquareWithPenisRight
    { .id = 62, .grid = {0b01, 0b11, 0b11}, .height = 3, .width = 2, .points = 5 },  // invsmallSquareWithPenisUp
    { .id = 63, .grid = {0b11, 0b11, 0b10}, .height = 3, .width = 2, .points = 5 },  // invsmallSquareWithPenisDown
    { .id = 64, .grid = {0b111, 0b011}, .height = 2, .width = 3, .points = 5 },  // invsmallSquareWithPenisLeft
    { .id = 65, .grid = {0b110, 0b111}, .height = 2, .width = 3, .points = 5 },  // invsmallSquareWithPenisRight
    { .id = 66, .grid = {0b0010, 0b1111}, .height = 2, .width = 4, .points = 5}, //FluteUp
    { .id = 67, .grid = {0b1111, 0b0100}, .height = 2, .width = 4, .points = 5}, //FluteDown
    { .id = 68, .grid = {0b01, 0b11, 0b01, 0b01}, .height = 4, .width = 2, .points = 5}, //FluteLeft
    { .id = 69, .grid = {0b10, 0b10, 0b11, 0b10}, .height = 4, .width = 2, .points = 5}, //FluteRight
    { .id = 70, .grid = {0b0100, 0b1111}, .height = 2, .width = 4, .points = 5}, //invFluteUp
    { .id = 71, .grid = {0b1111, 0b0010}, .height = 2, .width = 4, .points = 5}, //invFluteDown
    { .id = 72, .grid = {0b01, 0b01, 0b11, 0b01}, .height = 4, .width = 2, .points = 5}, //invFluteLeft
    { .id = 73, .grid = {0b10, 0b11, 0b10, 0b10}, .height = 4, .width = 2, .points = 5}, //invFluteRight
    { .id = 74, .grid = {0b010, 0b111, 0b111}, .height = 3, .width = 3, .points = 5}, //RectangleWithPenisUp
    { .id = 75, .grid = {0b110, 0b111, 0b110}, .height = 3, .width = 3, .points = 5}, //RectangleWithPenisRight
    { .id = 76, .grid = {0b111, 0b111, 0b010}, .height = 3, .width = 3, .points = 5}, //RectangleWithPenisDown
    { .id = 77, .grid = {0b011, 0b111, 0b011}, .height = 3, .width = 3, .points = 5}, //RectangleWithPenisLeft
    { .id = 78, .grid = {0b11, 0b11, 0b11, 0b11}, .height = 4, .width = 2, .points = 8}, //twoTimesFourRectStand
    { .id = 79, .grid = {0b1111, 0b1111}, .height = 2, .width = 4, .points = 8}, //twoTimesFourRectSide
    { .id = 80, .grid = {0b101, 0b101, 0b111}, .height = 3, .width = 3, .points = 7}, // UFormUp
    { .id = 81, .grid = {0b111, 0b101, 0b101}, .height = 3, .width = 3, .points = 7}, // UFormDown
    { .id = 82, .grid = {0b111, 0b001, 0b111}, .height = 3, .width = 3, .points = 7}, // UFormLeft
    { .id = 83, .grid = {0b111, 0b100, 0b111}, .height = 3, .width = 3, .points = 7}, // UFormRight
    { .id = 84, .grid = {0b10, 0b10, 0b10, 0b11, 0b01}, .height = 5, .width = 2, .points = 6}, // longZSmallBottom
    { .id = 85, .grid = {0b10, 0b11, 0b01, 0b01, 0b01}, .height = 5, .width = 2, .points = 6}, // longZSmallUp
    { .id = 86, .grid = {0b00011, 0b11110}, .height = 2, .width = 5, .points = 6}, // longZSmallRight
    { .id = 87, .grid = {0b01111, 0b11000}, .height = 2, .width = 5, .points = 6}, // longZSmallLeft
    { .id = 88, .grid = {0b01, 0b01, 0b01, 0b11, 0b10}, .height = 5, .width = 2, .points = 6}, // invlongZSmallBottom
    { .id = 89, .grid = {0b01, 0b11, 0b10, 0b10, 0b10}, .height = 5, .width = 2, .points = 6}, // invlongZSmallUp
    { .id = 90, .grid = {0b11110, 0b00011}, .height = 2, .width = 5, .points = 6}, // invlongZSmallRight
    { .id = 91, .grid = {0b11000, 0b01111}, .height = 2, .width = 5, .points = 6}, // invlongZSmallLeft
};



Tile getRandomTile() {
    size_t numTiles = sizeof(tiles) / sizeof(tiles[0]);
    size_t randomIndex;
    uint8_t isValidTile;

    uint8_t excludedList[] = { 0 };
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