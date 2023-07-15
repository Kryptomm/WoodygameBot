from math import sqrt
from time import sleep

import defines
import pyautogui
import tiles

def isBlockInSpace(img, x, y):
    avgColor = (0,0,0)
    for sub_x in range(-10, 11):
        for sub_y in range(-10 ,11):
            avgColor = tuple(ai + bi for ai, bi in zip(avgColor,
                                                        img.getpixel((int(x * defines.BOARD_BOX_WIDTH + sub_x + defines.HALFBLOCKWIDTH),
                                                                    int(y * defines.BOARD_BOX_HEIGHT + sub_y + defines.HALFBLOCKHEIGHT)))))
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

def getSingleTile(topLeft, bottomRight):
    screenshot = pyautogui.screenshot(region=(topLeft[0], topLeft[1], (bottomRight[0] - topLeft[0]), (bottomRight[1] - topLeft[1])))
    
    mid = (screenshot.width / 2, screenshot.width / 2)
    bestTile = [tiles.getTile(0), 0]
    
    for tile in tiles.tiles:
        xStart = int(mid[0] - tile.width / 2 * defines.INVENTORY_BOX_WIDTH)
        yStart = int(mid[1] - tile.height / 2 * defines.INVENTORY_BOX_HEIGHT)
        froundGrid = [0] * (tile.height)
        
        for y in range(0, tile.height):
            for x in range(0, tile.width):
                stY = yStart + y * defines.INVENTORY_BOX_HEIGHT
                stX = xStart + x * defines.INVENTORY_BOX_WIDTH
                
                avgColor = (0,0,0)
                for smallcubeY in range(0, defines.INVENTORY_BOX_HEIGHT):
                    for smallcubeX in range(0, defines.INVENTORY_BOX_WIDTH):
                        avgColor = tuple(ai + bi for ai, bi in zip(avgColor, screenshot.getpixel((int(stX + smallcubeX), int(stY + smallcubeY)))))
                        
                avgColor = tuple(ai / (defines.INVENTORY_BOX_HEIGHT * defines.INVENTORY_BOX_WIDTH) for ai in avgColor)
                distNotBlock = sqrt((avgColor[0] - defines.INVENTORY_BOX_COLOR_NOTPLACED[0])**2 + (avgColor[1] - defines.INVENTORY_BOX_COLOR_NOTPLACED[1])**2 + (avgColor[2] - defines.INVENTORY_BOX_COLOR_NOTPLACED[2])**2)
                distBlock = sqrt((avgColor[0] - defines.INVENTORY_BOX_COLOR_PLACED[0])**2 + (avgColor[1] - defines.INVENTORY_BOX_COLOR_PLACED[1])**2 + (avgColor[2] - defines.INVENTORY_BOX_COLOR_PLACED[2])**2) 
                
                froundGrid[y] = froundGrid[y] << 1
                if distBlock < distNotBlock / 3: froundGrid[y] += 1
        
        if tiles.compareTiles(tile.grid, froundGrid) and (bestTile[1] < tile.width or bestTile[1] < tile.height):
            bestTile = [tile, min(tile.width, tile.height)]
    return bestTile[0]

def getTiles():
    tile1 = getSingleTile(defines.INVENTORY_SLOT1_TOPLEFT, defines.INVENTORY_SLOT1_BOTTOMRIGHT)
    tile2 = getSingleTile(defines.INVENTORY_SLOT2_TOPLEFT, defines.INVENTORY_SLOT2_BOTTOMRIGHT)
    tile3 = getSingleTile(defines.INVENTORY_SLOT3_TOPLEFT, defines.INVENTORY_SLOT3_BOTTOMRIGHT)
    
    return [tile1, tile2, tile3]

if __name__ == "__main__":
    sleep(2)
    tiles = getSingleTile(defines.INVENTORY_SLOT2_TOPLEFT, defines.INVENTORY_SLOT2_BOTTOMRIGHT)
    print(tiles)