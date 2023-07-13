#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "defines.h"
#include "board.h"
#include "move.h"
#include "tiles.h"

int stringToInt(const char* str) {
    if (str == NULL || *str == '\0') {
        printf("Error: Empty string\n");
        return 0;
    }

    int result = 0;
    int i = 0;

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result;
}

void initBestMoveProgram(int argc, char *argv[], Inventory *inv){
    if (argc != (INVENTORY_SPACE + 2)) {
        printf("Nicht genug Argumente gegeben!");
        return;
    }
        
    //Board init
    for(uint8_t y = 0; y < BOARD_HEIGTH; y++){
        for(uint8_t x = 0; x < BOARD_WIDTH; x++){
            uint16_t index = y * BOARD_WIDTH + x;
            if (argv[1][index] == '1') setBlockOnBoard(x, y, 1);
            else setBlockOnBoard(x, y, 0);
        }
    }

    //Inventory Init
    for(uint8_t i = 0; i < INVENTORY_SPACE; i++){
        inv->tiles[i] = getTile(stringToInt(argv[i + 2]));
    }
}

void outputMove(Move move){
    FILE *file = fopen("outputBestMove", "w"); // Open the file in write mode
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }
    
    for(uint8_t i = 0; i < INVENTORY_SPACE; i++){
        fprintf(file, "%d %d %d\n", move.moves[i].tile.id, move.moves[i].x_position, move.moves[i].y_position);
    }
    
    fclose(file);
}