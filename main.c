#include <stdio.h>
#include <stdint.h>

#include "board.h"
#include "defines.h"

int main() {
    setBlockOnBoard(0,0,1);
    setBlockOnBoard(1,0,1);
    setBlockOnBoard(2,0,1);
    setBlockOnBoard(3,2,1);

    printBoard();
    return 0;
}