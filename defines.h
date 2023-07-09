#ifndef _DEFINES_H
#define _DEFINES_H

#include <stdint.h>

typedef uint16_t RowType;
typedef uint8_t TileType;
typedef uint16_t RewardType;

//TILES
#define MAX_TILE_HEIGHT 5

//BOARD
#define BOARD_WIDTH 8
#define BOARD_HEIGTH 8

//POINTS
#define FOUR_ATONCE_BONUS 200
#define FIVE_ATONCE_BONUS 300
#define SIX_ATONCE_BONUS 500

//OTHER
#define INVENTORY_SPACE 3

//COLORS
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#endif
