class Tile:
    def __init__(self, id, name, grid, height, width, points):
        self.id = id
        self.name = name
        self.grid = grid
        self.height = height
        self.width = width
        self.points = points

    def __repr__(self):
        return f"Tile(id={self.id}, name='{self.name}', grid={self.grid}, height={self.height}, width={self.width}, points={self.points})"

tiles = [
    Tile(0, "emptyTile", [], 0, 0, 0),
    Tile(1, "oneBlock", [0b1], 1, 1, 1),
    Tile(2, "twoBlockVertical", [0b1, 0b1], 2, 1, 2),
    Tile(3, "threeBlockVertical", [0b1, 0b1, 0b1], 3, 1, 3),
    Tile(4, "fourBlockVertical", [0b1, 0b1, 0b1, 0b1], 4, 1, 4),
    Tile(5, "fiveBlockVertical", [0b1, 0b1, 0b1, 0b1, 0b1], 5, 1, 5),
    Tile(6, "twoBlockHorizontal", [0b11], 1, 2, 2),
    Tile(7, "threeBlockHorizontal", [0b111], 1, 3, 3),
    Tile(8, "fourBlockHorizontal", [0b1111], 1, 4, 4),
    Tile(9, "fiveBlockHorizontal", [0b11111], 1, 5, 5),
    Tile(10, "bottomLeftBigL", [0b100, 0b100, 0b111], 3, 3, 5),
    Tile(11, "bottomRightBigL", [0b001, 0b001, 0b111], 3, 3, 5),
    Tile(12, "topLeftBigL", [0b111, 0b100, 0b100], 3, 3, 5),
    Tile(13, "topRightBigL", [0b111, 0b001, 0b001], 3, 3, 5),
    Tile(14, "smallSquare", [0b11, 0b11], 2, 2, 4),
    Tile(15, "bigSquare", [0b111, 0b111, 0b111], 3, 3, 9),
    Tile(16, "bottomLeftSmallL", [0b10, 0b11], 2, 2, 3),
    Tile(17, "bottomRightSmallL", [0b01, 0b11], 2, 2, 3),
    Tile(18, "topLeftSmallL", [0b11, 0b10], 2, 2, 3),
    Tile(19, "topRightSmallL", [0b11, 0b01], 2, 2, 3),
    Tile(20, "upTriangle", [0b010, 0b111], 2, 3, 4),
    Tile(21, "downTriangle", [0b111, 0b010], 2, 3, 4),
    Tile(22, "leftTriangle", [0b01, 0b11, 0b01], 3, 2, 4),
    Tile(23, "rightTriangle", [0b10, 0b11, 0b10], 3, 2, 4),
    Tile(24, "normLdown", [0b10, 0b10, 0b11], 3, 2, 4),
    Tile(25, "normLup", [0b11, 0b01, 0b01], 3, 2, 4),
    Tile(26, "normLleft", [0b111, 0b100], 2, 3, 4),
    Tile(27, "normLright", [0b001, 0b111], 2, 3, 4),
    Tile(28, "invLdown", [0b01, 0b01, 0b11], 3, 2, 4),
    Tile(29, "invLup", [0b11, 0b10, 0b10], 3, 2, 4),
    Tile(30, "invLleft", [0b100, 0b111], 2, 3, 4),
    Tile(31, "invLright", [0b111, 0b001], 2, 3, 4),
    Tile(32, "normSStand", [0b011, 0b110], 2, 3, 4),
    Tile(33, "normSSide", [0b10, 0b11, 0b01], 3, 2, 4),
    Tile(34, "invSStand", [0b110, 0b011], 2, 3, 4),
    Tile(35, "invSSide", [0b01, 0b11, 0b10], 3, 2, 4),
    Tile(36, "twoTimesThreeRecStand", [0b11, 0b11, 0b11], 3, 2, 6),
    Tile(37, "twoTimesThreeRecSide", [0b111, 0b111], 2, 3, 6),
    Tile(38, "bridgeHoleUp", [0b101, 0b111], 2, 3, 5),
    Tile(39, "bridgeHoleDown", [0b111, 0b101], 2, 3, 5),
    Tile(40, "bridgeHoleLeft", [0b11, 0b01, 0b11], 3, 2, 5),
    Tile(41, "bridgeHoleRight", [0b11, 0b10, 0b11], 3, 2, 5),
    Tile(42, "longLUp", [0b10, 0b10, 0b10, 0b11], 4, 2, 5),
    Tile(43, "longLDown", [0b11, 0b01, 0b01, 0b01], 4, 2, 5),
    Tile(44, "longLRight", [0b0001, 0b1111], 2, 4, 5),
    Tile(45, "longLLeft", [0b1111, 0b1000], 2, 4, 5),
    Tile(46, "invlongLUp", [0b01, 0b01, 0b01, 0b11], 4, 2, 5),
    Tile(47, "invlongLDown", [0b11, 0b10, 0b10, 0b10], 4, 2, 5),
    Tile(48, "invlongLRight", [0b1111, 0b0001], 2, 4, 5),
    Tile(49, "invlongLLeft", [0b1000, 0b1111], 2, 4, 5),
    Tile(50, "TformUp", [0b010, 0b010, 0b111], 3, 3, 5),
    Tile(51, "TformDown", [0b111, 0b010, 0b010], 3, 3, 5),
    Tile(52, "TformLeft", [0b001, 0b111, 0b001], 3, 3, 5),
    Tile(53, "TformRight", [0b100, 0b111, 0b100], 3, 3, 5),
    Tile(54, "ZformStand", [0b110, 0b010, 0b011], 3, 3, 5),
    Tile(55, "ZformSide", [0b001, 0b111, 0b100], 3, 3, 5),
    Tile(56, "invZformStand", [0b011, 0b010, 0b110], 3, 3, 5),
    Tile(57, "invZformSide", [0b100, 0b111, 0b001], 3, 3, 5),
    Tile(58, "smallSquareWithPenisUp", [0b10, 0b11, 0b11], 3, 2, 5),
    Tile(59, "smallSquareWithPenisDown", [0b11, 0b11, 0b01], 3, 2, 5),
    Tile(60, "smallSquareWithPenisLeft", [0b011, 0b111], 2, 3, 5),
    Tile(61, "smallSquareWithPenisRight", [0b111, 0b110], 2, 3, 5),
    Tile(62, "invsmallSquareWithPenisUp", [0b01, 0b11, 0b11], 3, 2, 5),
    Tile(63, "invsmallSquareWithPenisDown", [0b11, 0b11, 0b10], 3, 2, 5),
    Tile(64, "invsmallSquareWithPenisLeft", [0b111, 0b011], 2, 3, 5),
    Tile(65, "invsmallSquareWithPenisRight", [0b110, 0b111], 2, 3, 5)
]

def compareTiles(tile1, tile2):
    if len(tile1) !=len(tile2): return False
    for y in range(len(tile1)):
        if tile1[y] != tile2[y]:
            return False
    return True

def getTile(num):
    return tiles[num]

if __name__ == "__main__":
    for t in tiles:
        if compareTiles(t.grid, [0b110, 0b011]): print(t)