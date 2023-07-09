#include <stdio.h>
#include <stdint.h>

#include "board.h"
#include "defines.h"
#include "tiles.h"

int main() {
    initTiles();

    Tile randTile;
    randTile = getRandomTile();
    
    placeTileOnBoard(&randTile,1,1);

    printBoard();
    return 0;
}