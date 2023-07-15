#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h> 

#include "board.h"
#include "defines.h"
#include "tiles.h"
#include "reward.h"
#include "move.h"
#include "communicator.h"

uint16_t roundsPlayed = 0;
long pointsTotal = 0;
long points = 0;
long bestPoints = 0;

void playGame() {
    while(1) {
        Inventory inv = getRandomInventory();

        Move move = getBestMove(&inv);

        if(!move.isPlaceable){
            printf("VERLOREN: %d\nTiles:\n", points);
            printTile(&(inv.tiles[0]));
            printTile(&(inv.tiles[1]));
            printTile(&(inv.tiles[2]));

            if(points > bestPoints){
                bestPoints = points;
            }
            points = 0;
            roundsPlayed = roundsPlayed + 1;
            return;
        }

        for(uint8_t i = 0; i < 3; i++){
            placeTileOnBoard(&(move.moves[i].tile), move.moves[i].x_position,  move.moves[i].y_position);
            points += move.moves[i].tile.points; 
            points += 10 * cleanFullRows(&(move.moves[i].tile), move.moves[i].x_position,  move.moves[i].y_position);
        }

        printBoard();
        printf("Current Points: %d Best Points: %d, Round: %d\n", points, bestPoints, roundsPlayed);
    }
}

void simulate(){
    while(roundsPlayed < MAX_ROUNDS){
        playGame();
        printf("AVERAGE: %d\n", pointsTotal / roundsPlayed);
    }
}

void bestMove(int argc, char *argv[]){
    //Init
    Inventory inv;
    initBestMoveProgram(argc, argv, &inv);

    printBoard();
    //Calc
    Move move = getBestMove(&inv);

    //Output
    outputMove(move);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    if (IS_SIMULATING) simulate();
    else bestMove(argc, argv);
}