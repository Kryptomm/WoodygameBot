import defines
import pyautogui
import math

from time import sleep

def getTimeToMove(startX, startY, endX, endY):
    dist = math.sqrt((startX - endX)**2 + (startY - endY)**2)
    return dist * defines.PIXELMULTIPLIER

def moveTileToCoordinates(tile, slot, x, y):
    startCoordinates = None
    if slot == 1: startCoordinates = defines.INVENTORY_SLOT1_MID
    elif slot == 2: startCoordinates = defines.INVENTORY_SLOT2_MID
    elif slot == 3: startCoordinates = defines.INVENTORY_SLOT3_MID
    
    pyautogui.moveTo(startCoordinates)
    
    desiredY = (y + defines.PLACEMENT_HEIGHT_DELTA + tile.height) * defines.BOARD_BOX_HEIGHT + defines.BOARD_TOPLEFT[1]
    desiredX = (x + int(tile.width / 2)) * defines.BOARD_BOX_WIDTH + defines.BOARD_TOPLEFT[0]
    
    if tile.width % 2 == 1: desiredX += defines.HALFBLOCKWIDTH
    
    pyautogui.mouseDown(button='left')
    time = getTimeToMove(*startCoordinates, desiredX, desiredY)
    pyautogui.moveTo(desiredX, desiredY, time) 
    sleep(defines.MOVETIMEWAIT)
    pyautogui.mouseUp(button='left')

if __name__ == "__main__":

    import tiles
    
    moveTileToCoordinates(tiles.tiles[18], 2, 0, 2)