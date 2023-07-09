#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "board.h"
#include "defines.h"
#include "tiles.h"
#include "reward.h"

int main() {
    initTiles();

    Tile tile1;
    Tile tile2;
    Tile tile3;
    Tile tile4;

    tile1 = fourBlockHorizontal;
    tile2 = threeBlockHorizontal;
    tile3 = bottomLeftSmallL;
    tile4 = threeBlockVertical;
    placeTileOnBoard(&tile1, 1, 0);
    placeTileOnBoard(&tile2, 2, 1);
    placeTileOnBoard(&tile4, 0, 2);
    placeTileOnBoard(&tile4, 1, 2);
    placeTileOnBoard(&tile2, 2, 4);

    printf("Reward: %d\n", judgeBoard(board));
    cleanFullRows(&tile2, 2,4);

    printBoard();

    placeTileOnBoard(&tile3, 0, 0);
    cleanFullRows(&tile3, 0,0);

    printBoard();

    return 0;
}