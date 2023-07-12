#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h> 

#include "board.h"
#include "defines.h"
#include "tiles.h"
#include "reward.h"
#include "move.h"

uint64_t points;
uint64_t bestPoints;

void playRound() {
    while(1) {
        Inventory inv = getRandomInventory();

        Move move = getBestMove(inv);

        if(!move.isPlaceable){
            printf("VERLOREN: %d\nTiles:\n", points);
            printTile(&(inv.tiles[0]));
            printTile(&(inv.tiles[1]));
            printTile(&(inv.tiles[2]));

            if(points > bestPoints){
                bestPoints = points;
            }
            points = 0;
            return;
        }

        for(uint8_t i = 0; i < 3; i++){
            placeTileOnBoard(&(move.moves[i].tile), move.moves[i].x_position,  move.moves[i].y_position);
            points += move.moves[i].tile.points; 
            points += 10 * cleanFullRows(&(move.moves[i].tile), move.moves[i].x_position,  move.moves[i].y_position);
        }

        printBoard();
        printf("Current Points: %d\n", points);
        printf("BEST POINTS: %d\n", bestPoints);
    }
}

int main() {
    initTiles();

    srand(time(NULL));

    while(1){
        playRound();
    }
    return 0;
}