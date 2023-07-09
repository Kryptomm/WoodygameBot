#include <stdio.h>
#include <stdint.h>

#include "board.h"
#include "defines.h"
#include "tiles.h"
#include "reward.h"

int main() {
    initTiles();

    Tile randTile;
    randTile = getRandomTile();
    
    placeTileOnBoard(&randTile,1,1);

    printf("%d\n", judgeBoard(getBoard));

    printBoard();
    return 0;
}