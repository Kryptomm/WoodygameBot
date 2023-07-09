#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "board.h"
#include "defines.h"
#include "tiles.h"
#include "reward.h"
#include "move.h"

uint32_t points;

void playRound() {
    while(1) {
        Inventory inv = getRandomInventory();
        Move move = getBestMove(inv);

        //if(move.moves[0].x_position  == BOARD_WIDTH) return;

        //printBoard();
        return;
    }
}

int main() {
    initTiles();

    playRound();

    return 0;
}