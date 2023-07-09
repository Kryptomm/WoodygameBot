#include <stdio.h>
#include <stdint.h>

#include "board.h"
#include "defines.h"
#include "tiles.h"

int main() {
    printf("%d\n", isPlaceable(&twoBlockHorizontal, 0, 0));
    placeTileOnBoard(&fiveBlockHorizontal,0,0);

    printBoard();
    return 0;
}