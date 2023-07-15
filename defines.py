BOARD_WIDTH = 10
BOARD_HEIGHT = 10

BOARD_TOPLEFT = (760,259)
BOARD_BOTTOMRIGHT = (1159, 659)

BOARD_BOX_WIDTH = (BOARD_BOTTOMRIGHT[0] - BOARD_TOPLEFT[0]) / BOARD_WIDTH
BOARD_BOX_HEIGHT = (BOARD_BOTTOMRIGHT[1] - BOARD_TOPLEFT[1]) / BOARD_HEIGHT

HALFBLOCKWIDTH = BOARD_BOX_WIDTH / 2
HALFBLOCKHEIGHT = BOARD_BOX_HEIGHT / 2

PLACED_COLOR = (180, 158, 127)
NOTPLACED_COLOR = (97, 11, 1)

INVENTORY_SLOT1_TOPLEFT = (749,745)
INVENTORY_SLOT1_BOTTOMRIGHT = (860,856)

INVENTORY_SLOT2_TOPLEFT = (904,745)
INVENTORY_SLOT2_BOTTOMRIGHT = (1015,856)

INVENTORY_SLOT3_TOPLEFT = (1059,745)
INVENTORY_SLOT3_BOTTOMRIGHT = (1170,856)

INVENTORY_BOX_WIDTH = 17
INVENTORY_BOX_HEIGHT = 17

INVENTORY_BOX_COLOR_PLACED = (167, 144, 115)
INVENTORY_BOX_COLOR_NOTPLACED = (96, 11, 0)


INVENTORY_SLOT1_MID = ((INVENTORY_SLOT1_BOTTOMRIGHT[0] + INVENTORY_SLOT1_TOPLEFT[0]) / 2, (INVENTORY_SLOT1_BOTTOMRIGHT[1] + INVENTORY_SLOT1_TOPLEFT[1]) / 2)
INVENTORY_SLOT2_MID = ((INVENTORY_SLOT2_BOTTOMRIGHT[0] + INVENTORY_SLOT2_TOPLEFT[0]) / 2, (INVENTORY_SLOT2_BOTTOMRIGHT[1] + INVENTORY_SLOT2_TOPLEFT[1]) / 2)
INVENTORY_SLOT3_MID = ((INVENTORY_SLOT3_BOTTOMRIGHT[0] + INVENTORY_SLOT3_TOPLEFT[0]) / 2, (INVENTORY_SLOT3_BOTTOMRIGHT[1] + INVENTORY_SLOT3_TOPLEFT[1]) / 2)

PLACEMENT_HEIGHT_DELTA = 1.9

MOVETIME = 0.5
MOVETIMEWAIT= 0.15
TIME_AFTER_TURN = 1
PIXELMULTIPLIER = 0.0009