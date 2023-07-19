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


int playGame() {
    RowType* board[BOARD_HEIGTH] = {0};
    int points = 0;
    while(1) {
        Inventory* inv = getRandomInventory();
        Move move = getBestMove(inv, board);

        if(!move.isPlaceable){
            printBoard(board);
            printf("TILES:\n");
            printTile(&(inv->tiles[0]));
            printTile(&(inv->tiles[1]));
            printTile(&(inv->tiles[2]));

            printf("\nVERLOREN: %d\n", points);

            free(inv);
            return points;
        }

        for(uint8_t i = 0; i < 3; i++){
            placeTileOnBoard(&(move.moves[i].tile), move.moves[i].x_position,  move.moves[i].y_position, board);
            points += move.moves[i].tile.points; 
            points += 10 * cleanFullRows(&(move.moves[i].tile), move.moves[i].x_position,  move.moves[i].y_position, board);
        }

        printBoard(board);
        printf("Board Points: %ld Current Points: %d\n", move.points ,points);

        free(inv);
    }
}

int simulateSpec(){
    int roundsPlayed = 0;
    int pointsTotal = 0;
    int bestPoints = 0;
    int avg = 0;
    while(roundsPlayed < MAX_ROUNDS){
        roundsPlayed++;
        int points = playGame();
        pointsTotal += points;

        if(points > bestPoints){
            bestPoints = points;
        }

        avg = pointsTotal / roundsPlayed;
        printf("AVERAGE: %d TOTAL: %d PLAYED: %d BEST: %d", avg, pointsTotal, roundsPlayed, bestPoints);
    }
    return avg;
}

void bestMove(int argc, char* argv[]) {
    //Init
    Inventory inv;
    RowType board[BOARD_HEIGTH] = {0}; // Create a board instance
    initBestMoveProgram(argc, argv, &inv, board); // Pass the board instance

    printBoard(board); // Pass the board instance

    //Calc
    Move move = getBestMove(&inv, board); // Pass the board instance

    //Output
    outputMove(move);
}


int main(int argc, char *argv[]) {
    srand(time(NULL));

    switch(MODE){
        case 0:
            bestMove(argc, argv);
            break;
        case 1:
            simulateSpec();
            break;
    }
}