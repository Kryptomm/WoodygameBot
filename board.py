class Board:
    def __init__(self, width, heigth):
        self.width = width
        self.heigth = heigth
        self.board = [[0] * width] * heigth
        
    def printBoard(self):
        res = ""
        for x in range(self.width):
            for y in range(self.heigth):
                if self.board[y][x] == 1: print("🟩", end="")
                elif self.board[y][x] == 0: print("🟥", end="")
            print("")
            
            
        

if __name__ == "__main__":
    gameBoard = Board(10,10)
    gameBoard.printBoard()