class Board:
    def __init__(self, width, heigth):
        self.width = width
        self.heigth = heigth
        self.board = [[0 for _ in range(width)] for _ in range(heigth)]
        self.points = 0
        
    def printBoard(self):
        for y in range(self.heigth):
            for x in range(self.width):
                if self.board[y][x] == 1: print("🟩", end="")
                elif self.board[y][x] == 0: print("🟥", end="")
            print("")
            
    def placePiece(self, piece, x, y, countPoints=False):
        if not piece.fitsAtPosition(self, x, y): return False

        for xp in range(0, piece.width):
            for yp in range(0, piece.heigth):
                self.board[yp + y][xp + x] |= piece.piece[yp][xp]
        
        if countPoints: self.points += piece.points
        return True
    
    def deletePiece(self, piece, x , y):
        for xp in range(0, piece.width):
            for yp in range(0, piece.heigth):
                self.board[yp + y][xp + x] &= ~(piece.piece[yp][xp])
        

    def __freeSpacePoints(self):
        count = self.heigth * self.width
        for y in range(self.heigth):
            for x in range(self.width):
                if self.board[y][x] == 1: count -= 1
        return count
    
    
    
    def getPoints(self):
        return self.__freeSpacePoints()