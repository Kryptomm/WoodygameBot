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
#ifdef _WIN32 // Check for Windows platform
    #include <windows.h>
    typedef HANDLE My_pthread_t;
    typedef CRITICAL_SECTION My_pthread_mutex_t;
    #define PTHREAD_MUTEX_INIT(mutex, attr) InitializeCriticalSection(mutex)
    #define PTHREAD_MUTEX_LOCK(mutex) EnterCriticalSection(mutex)
    #define PTHREAD_MUTEX_UNLOCK(mutex) LeaveCriticalSection(mutex)
    #define PTHREAD_MUTEX_DESTROY(mutex) DeleteCriticalSection(mutex)
#else // Assume POSIX (Linux/macOS) platform
    #include <pthread.h>
    typedef pthread_t My_pthread_t;
    typedef pthread_mutex_t My_pthread_mutex_t;
    #define PTHREAD_MUTEX_INIT(mutex, attr) pthread_mutex_init(mutex, attr)
    #define PTHREAD_MUTEX_LOCK(mutex) pthread_mutex_lock(mutex)
    #define PTHREAD_MUTEX_UNLOCK(mutex) pthread_mutex_unlock(mutex)
    #define PTHREAD_MUTEX_DESTROY(mutex) pthread_mutex_destroy(mutex)
#endif

#endif
