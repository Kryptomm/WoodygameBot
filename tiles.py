class Tile:
    def __init__(self, id, grid, height, width, points):
        self.id = id
        self.grid = grid
        self.height = height
        self.width = width
        self.points = points

tiles = [
    Tile(0, [], 0, 0, 0),                            # emptyTile
    Tile(1, [0b1], 1, 1, 1),                          # oneBlock
    Tile(2, [0b1, 0b1], 2, 1, 2),                     # twoBlockVertical
    Tile(3, [0b1, 0b1, 0b1], 3, 1, 3),                # threeBlockVertical
    Tile(4, [0b1, 0b1, 0b1, 0b1], 4, 1, 4),           # fourBlockVertical
    Tile(5, [0b1, 0b1, 0b1, 0b1, 0b1], 5, 1, 5),      # fiveBlockVertical
    Tile(6, [0b11], 1, 2, 2),                         # twoBlockHorizontal
    Tile(7, [0b111], 1, 3, 3),                        # threeBlockHorizontal
    Tile(8, [0b1111], 1, 4, 4),                       # fourBlockHorizontal
    Tile(9, [0b11111], 1, 5, 5),                      # fiveBlockHorizontal
    Tile(10, [0b100, 0b100, 0b111], 3, 3, 5),         # bottomLeftBigL
    Tile(11, [0b001, 0b001, 0b111], 3, 3, 5),         # bottomRightBigL
    Tile(12, [0b111, 0b100, 0b100], 3, 3, 5),         # topLeftBigL
    Tile(13, [0b111, 0b001, 0b001], 3, 3, 5),         # topRightBigL
    Tile(14, [0b11, 0b11], 2, 2, 4),                  # smallSquare
    Tile(15, [0b111, 0b111, 0b111], 3, 3, 9),         # bigSquare
    Tile(16, [0b10, 0b11], 2, 2, 3),                  # bottomLeftSmallL
    Tile(17, [0b01, 0b11], 2, 2, 3),                  # bottomRightSmallL
    Tile(18, [0b11, 0b10], 2, 2, 3),                  # topLeftSmallL
    Tile(19, [0b11, 0b01], 2, 2, 3),                  # topRightSmallL
    Tile(20, [0b010, 0b111], 2, 3, 4),                # upTriangle
    Tile(21, [0b111, 0b010], 2, 3, 4),                # downTriangle
    Tile(22, [0b01, 0b11, 0b01], 3, 2, 4),            # leftTriangle
    Tile(23, [0b10, 0b11, 0b10], 3, 2, 4),            # rightTriangle
    Tile(24, [0b10, 0b10, 0b11], 3, 2, 4),            # normLdown
    Tile(25, [0b11, 0b01, 0b01], 3, 2, 4),            # normLup
    Tile(26, [0b111, 0b100], 2, 3, 4),                # normLleft
    Tile(27, [0b001, 0b111], 2, 3, 4),                # normLright
    Tile(28, [0b01, 0b01, 0b11], 3, 2, 4),            # invLdown
    Tile(29, [0b11, 0b10, 0b10], 3, 2, 4),            # invLup
    Tile(30, [0b100, 0b111], 2, 3, 4),                # invLleft
    Tile(31, [0b111, 0b001], 2, 3, 4),                # invLright
    Tile(32, [0b011, 0b110], 2, 3, 4),                # normSStand
    Tile(33, [0b10, 0b11, 0b01], 3, 2, 4),            # normSSide
    Tile(34, [0b110, 0b011], 2, 3, 4),                # invSStand
    Tile(35, [0b01, 0b11, 0b10], 3, 2, 4),            # invSSide
    Tile(36, [0b11, 0b11, 0b11], 3, 2, 6),            # twoTimesThreeRecStand
    Tile(37, [0b111, 0b111], 2, 3, 6),                # twoTimesThreeRecSide
    Tile(38, [0b101, 0b111], 2, 3, 5),                # bridgeHoleUp
    Tile(39, [0b111, 0b101], 2, 3, 5),                # bridgeHoleDown
    Tile(40, [0b11, 0b01, 0b11], 3, 2, 5),            # bridgeHoleLeft
    Tile(41, [0b11, 0b10, 0b11], 3, 2, 5)             # bridgeHoleRight
]

def getTile(num):
    return tiles(num)