import defines
import pyautogui

from time import sleep

def moveTileToCoordinates(tile, slot, x, y):
    if slot == 1: pyautogui.moveTo(defines.INVENTORY_SLOT1_MID)
    elif slot == 2: pyautogui.moveTo(defines.INVENTORY_SLOT2_MID)
    elif slot == 3: pyautogui.moveTo(defines.INVENTORY_SLOT3_MID)
    
    desiredY = (y + defines.PLACEMENT_HEIGHT_DELTA + tile.height) * defines.BOARD_BOX_HEIGHT + defines.BOARD_TOPLEFT[1]
    desiredX = (x + int(tile.width / 2)) * defines.BOARD_BOX_WIDTH + defines.BOARD_TOPLEFT[0]
    
    if tile.width % 2 == 1: desiredX += defines.HALFBLOCKWIDTH
    
    pyautogui.mouseDown(button='left')
    pyautogui.moveTo(desiredX, desiredY, 1) 
    sleep(0.25)
    pyautogui.mouseUp(button='left')

if __name__ == "__main__":

    import tiles
    
    sleep(2)
    moveTileToCoordinates(tiles.tiles[18], 2, 0, 2)