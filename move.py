import defines
import pyautogui

def moveTileToCoordinates(tile, slot, x, y):
    if slot == 1: pyautogui.moveTo(defines.INVENTORY_SLOT1)
    elif slot == 2: pyautogui.moveTo(defines.INVENTORY_SLOT2)
    elif slot == 3: pyautogui.moveTo(defines.INVENTORY_SLOT3)
    
    desiredY = (y + defines.PLACEMENT_HEIGHT_DELTA + tile.height - 1) * defines.BOARD_BOX_HEIGHT + defines.BOARD_TOPLEFT[1] + defines.HALFBLOCKHEIGHT
    desiredX = (x+ int(tile.width / 2)) * defines.BOARD_BOX_WIDTH + defines.BOARD_TOPLEFT[0] + defines.HALFBLOCKWIDTH 
    
    if tile.width % 2 == 0:
        desiredX += defines.HALFBLOCKWIDTH
    
    pyautogui.dragTo(desiredX, desiredY, 2,button='left') 


if __name__ == "__main__":
    from time import sleep
    import tiles
    
    sleep(2)
    moveTileToCoordinates(tiles.tiles[12], 1, 0, 0)