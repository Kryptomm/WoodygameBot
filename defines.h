#ifndef _DEFINES_H
#define _DEFINES_H

#include <stdint.h>

typedef uint16_t RowType;
typedef uint8_t TileType;
typedef long RewardType;

//BEHAVIOUR
#define IS_SIMULATING 1
#define MAX_ROUNDS 1

//TILES
#define MAX_TILE_HEIGHT 5

//BOARD
#define BOARD_WIDTH 10
#define BOARD_HEIGTH 10

//REWARDS
#define REWARD_SCALE_MULTIPLIER 100000

//INVENTORY
#define INVENTORY_SPACE 3

//COLORS
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Mutex Defines
#ifdef _WIN32 // Windows
    #include <windows.h>
    #define MUTEX_TYPE HANDLE
    #define MUTEX_INIT(mutex) mutex = CreateMutex(NULL, FALSE, NULL)
    #define MUTEX_LOCK(mutex) WaitForSingleObject(mutex, INFINITE)
    #define MUTEX_UNLOCK(mutex) ReleaseMutex(mutex)
    #define MUTEX_DESTROY(mutex) CloseHandle(mutex)
#else // Assume POSIX (Linux, macOS, etc.)
    #include <pthread.h>
    #define MUTEX_TYPE pthread_mutex_t
    #define MUTEX_INIT(mutex) pthread_mutex_init(&mutex, NULL)
    #define MUTEX_LOCK(mutex) pthread_mutex_lock(&mutex)
    #define MUTEX_UNLOCK(mutex) pthread_mutex_unlock(&mutex)
    #define MUTEX_DESTROY(mutex) pthread_mutex_destroy(&mutex)
#endif

#endif
