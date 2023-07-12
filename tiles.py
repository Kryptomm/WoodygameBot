class Tile:
    def __init__(self, grid, height, width, points):
        self.grid = grid
        self.height = height
        self.width = width
        self.points = points


tiles = [None] * 42

tiles[0] = Tile([], 0, 0, 0)  # emptyTile
tiles[1] = Tile([0b1], 1, 1, 1)  # oneBlock
tiles[2] = Tile([0b1, 0b1], 2, 1, 2)  # twoBlockVertical
tiles[3] = Tile([0b1, 0b1, 0b1], 3, 1, 3)  # threeBlockVertical
tiles[4] = Tile([0b1, 0b1, 0b1, 0b1], 4, 1, 4)  # fourBlockVertical
tiles[5] = Tile([0b1, 0b1, 0b1, 0b1, 0b1], 5, 1, 5)  # fiveBlockVertical
tiles[6] = Tile([0b11], 1, 2, 2)  # twoBlockHorizontal
tiles[7] = Tile([0b111], 1, 3, 3)  # threeBlockHorizontal
tiles[8] = Tile([0b1111], 1, 4, 4)  # fourBlockHorizontal
tiles[9] = Tile([0b11111], 1, 5, 5)  # fiveBlockHorizontal
tiles[10] = Tile([0b100, 0b100, 0b111], 3, 3, 5)  # bottomLeftBigL
tiles[11] = Tile([0b001, 0b001, 0b111], 3, 3, 5)  # bottomRightBigL
tiles[12] = Tile([0b111, 0b100, 0b100], 3, 3, 5)  # topLeftBigL
tiles[13] = Tile([0b111, 0b001, 0b001], 3, 3, 5)  # topRightBigL
tiles[14] = Tile([0b11, 0b11], 2, 2, 4)  # smallSquare
tiles[15] = Tile([0b111, 0b111, 0b111], 3, 3, 9)  # bigSquare
tiles[16] = Tile([0b10, 0b11], 2, 2, 3)  # bottomLeftSmallL
tiles[17] = Tile([0b01, 0b11], 2, 2, 3)  # bottomRightSmallL
tiles[18] = Tile([0b11, 0b10], 2, 2, 3)  # topLeftSmallL
tiles[19] = Tile([0b11, 0b01], 2, 2, 3)  # topRightSmallL
tiles[20] = Tile([0b010, 0b111], 2, 3, 4)  # upTriangle
tiles[21] = Tile([0b111, 0b010], 2, 3, 4)  # downTriangle
tiles[22] = Tile([0b01, 0b11, 0b01], 3, 2, 4)  # leftTriangle
tiles[23] = Tile([0b10, 0b11, 0b10], 3, 2, 4)  # rightTriangle
tiles[24] = Tile([0b10, 0b10, 0b11], 3, 2, 4)  # normLdown
tiles[25] = Tile([0b11, 0b01, 0b01], 3, 2, 4)  # normLup
tiles[26] = Tile([0b111, 0b100], 2, 3, 4)  # normLleft
tiles[27] = Tile([0b001, 0b111], 2, 3, 4)  # normLright
tiles[28] = Tile([0b01, 0b01, 0b11], 3, 2, 4)  # invLdown
tiles[29] = Tile([0b11, 0b10, 0b10], 3, 2, 4)  # invLup
tiles[30] = Tile([0b100, 0b111], 2, 3, 4)  # invLleft
tiles[31] = Tile([0b111, 0b001], 2, 3, 4)  # invLright
tiles[32] = Tile([0b011, 0b110], 2, 3, 4)  # normSStand
tiles[33] = Tile([0b10, 0b11, 0b01], 3, 2, 4)  # normSSide
tiles[34] = Tile([0b110, 0b011], 2, 3, 4)  # invSStand
tiles[35] = Tile([0b01, 0b11, 0b10], 3, 2, 4)  # invSSide
tiles[36] = Tile([0b11, 0b11, 0b11], 3, 2, 6)  # twoTimesThreeRecStand
tiles[37] = Tile([0b111, 0b111], 2, 3, 6)  # twoTimesThreeRecSide
tiles[38] = Tile([0b101, 0b111], 2, 3, 5)  # bridgeHoleUp
tiles[39] = Tile([0b111, 0b101], 2, 3, 5)  # bridgeHoleDown
tiles[40] = Tile([0b11, 0b01, 0b11], 3, 2, 5)  # bridgeHoleLeft
tiles[41] = Tile([0b11, 0b10, 0b11], 3, 2, 5)  # bridgeHoleRight
