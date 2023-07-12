from math import sqrt

from time import sleep

import defines
import pyautogui

def isBlockInSpace(img, x, y):
    HALFBLOCKWIDTH = defines.BOARD_BOX_WIDTH / 2
    HALFBLOCKHEIGHT = defines.BOARD_BOX_HEIGHT / 2
    
    avgColor = (0,0,0)
    for sub_x in range(-10, 11):
        for sub_y in range(-10 ,11):
            avgColor = tuple(ai + bi for ai, bi in zip(avgColor,
                                                        img.getpixel((int(x * defines.BOARD_BOX_WIDTH + sub_x + HALFBLOCKWIDTH),
                                                                    int(y * defines.BOARD_BOX_HEIGHT + sub_y + HALFBLOCKHEIGHT)))))
    avgColor = tuple(ai / 441 for ai in avgColor) 
    distNotBlock = sqrt((avgColor[0] - defines.NOTPLACED_COLOR[0])**2 + (avgColor[1] - defines.NOTPLACED_COLOR[1])**2 + (avgColor[2] - defines.NOTPLACED_COLOR[2])**2)
    distBlock = sqrt((avgColor[0] - defines.PLACED_COLOR[0])**2 + (avgColor[1] - defines.PLACED_COLOR[1])**2 + (avgColor[2] - defines.PLACED_COLOR[2])**2)
    
    if distBlock < distNotBlock: return 1
    else: return 0

def getBoardFromScreen():
    screenshot = pyautogui.screenshot(region=(defines.BOARD_TOPLEFT[0],
                                            defines.BOARD_TOPLEFT[1],
                                            (defines.BOARD_BOTTOMRIGHT[0] - defines.BOARD_TOPLEFT[0]),
                                            (defines.BOARD_BOTTOMRIGHT[1] - defines.BOARD_TOPLEFT[1])))
    
    board = [[0] * defines.BOARD_WIDTH for _ in range(defines.BOARD_HEIGHT)]
    
    for x in range(0, defines.BOARD_WIDTH):
        for y in range(0, defines.BOARD_HEIGHT):
            if isBlockInSpace(screenshot, x, y):
                board[y][x] = 1
    
    return board


if __name__ == "__main__":
    sleep(2)
    board = getBoardFromScreen()
    for y in range(0, defines.BOARD_HEIGHT):
        for x in range(0, defines.BOARD_WIDTH):
            print(f"{board[y][x]} ", end="")
        print("")