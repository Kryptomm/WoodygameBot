from random import randint

class Piece:
    def __init__(self, array):
        self.piece = array
        self.width =  len(array[0])
        self.heigth = len(array)
    
    def printPiece(self):
        for y in range(self.heigth):
            for x in range(self.width):
                if self.piece[y][x] == 1: print("🟩", end="")
                elif self.piece[y][x] == 0: print("🟥", end="")
            print("")
    
    def fitsAtPosition(self, board, x, y):
        if x + self.width > board.width: return False
        if y + self.heigth > board.heigth: return False
        
        gameBoard = board.board
        for xp in range(0, self.width):
            for yp in range(0, self.heigth):
                if (gameBoard[yp + y][xp + x] & self.piece[yp][xp]) >= 1:
                    return False
        return True
        
        return
    
    def boardCoordGenerator(self, board):
        for y in range(board.width):
            for x in range(board.heigth):
                if self.fitsAtPosition(board, x, y): yield (x,y)
                

class PieceManager:
    def __init__(self):
        self.PIECES = [
                Piece([
                    [1]
                ]),
                
                Piece([
                    [1,1]
                ]),
                
                Piece([
                    [1,1,1]
                ]),
                
                Piece([
                    [1,1,1,1]
                ]),
                
                Piece([
                    [1,1,1,1,1]
                ]),
        ]
        
    def getRandomPiece(self):
        return self.PIECES[randint(0,len(self.PIECES) - 1)]