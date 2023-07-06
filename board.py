class Board:
    def __init__(self, width, heigth):
        self.width = width
        self.heigth = heigth
        self.board = [[0] * width] * heigth
        
    def __repr__(self):
        for x in range(self.width):
            for y in range(self.heigth):
                print(self.board[y][x], end="")
            print("")