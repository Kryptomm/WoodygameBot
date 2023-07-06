class Board:
    def __init__(self, width, heigth):
        self.width = width
        self.heigth = heigth
        self.board = [[0] * width] * heigth
        
    def printBoard(self):
        for y in range(self.heigth):
            for x in range(self.width):
                if self.board[y][x] == 1: print("🟩", end="")
                elif self.board[y][x] == 0: print("🟥", end="")
            print("")
            
    def placePiece(self, piece, x, y):
        if not piece.fitsAtPosition(self, x, y): return False

        for xp in range(0, piece.width):
            for yp in range(0, piece.heigth):
                self.board[yp + y][xp + x] |= piece.piece[yp][xp]
        return True
