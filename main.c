#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "board.h"
#include "defines.h"
#include "tiles.h"
#include "reward.h"

int main() {
    initTiles();

    srandom(time(NULL));
    for(int i = 0; i < 5; i++){
        Tile randTile;
        randTile = getRandomTile();
        placeTileOnBoard(&randTile, (uint8_t) (random() % BOARD_WIDTH), (uint8_t) (random() % BOARD_HEIGTH));
    }
    
    printBoard();

    printf("Reward: %d",judgeBoard(board));

    return 0;
}