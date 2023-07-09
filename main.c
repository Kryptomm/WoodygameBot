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
    int maxSteps = 1000;
    int steps = 0;
    while(1 && steps < maxSteps) {
        Inventory inv = getRandomInventory();

        Move move = getBestMove(inv);

        if(!move.isPlaceable){
            printf("VERLOREN: %d", points);
            return;
        }

        for(uint8_t i = 0; i < 3; i++){
            placeTileOnBoard(&(move.moves[i].tile), move.moves[i].x_position,  move.moves[i].y_position);
            points += move.moves[i].tile.points; 
            points += 10 * cleanFullRows(&(move.moves[i].tile), move.moves[i].x_position,  move.moves[i].y_position);
        }

        printBoard();
        steps++;
    }
}

int main() {
    initTiles();

    playRound();

    return 0;
}