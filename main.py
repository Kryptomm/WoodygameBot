import itertools

from board import Board
from pieces import Piece, PieceManager

PIECEMANAGER = PieceManager()

def getBestMove(board, pieces):
    bestMove = None
    bestScore = float("-inf")
    for perm in list(itertools.permutations(pieces)):
        for (x1,y1) in perm[0].boardCoordGenerator(board):
            board.placePiece(perm[0],x1,y1)
            
            for (x2,y2) in perm[1].boardCoordGenerator(board):
                board.placePiece(perm[1],x2,y2)
                
                for (x3,y3) in perm[2].boardCoordGenerator(board):
                    board.placePiece(perm[2],x3,y3)
                    
                    score = board.getPoints()
                    if score > bestScore:
                        bestMove = [(perm[0],x1,y1),(perm[1],x2,y2),(perm[2],x3,y3)]
                        bestScore = score
                    
                    board.deletePiece(perm[2],x3,y3)
                board.deletePiece(perm[1],x2,y2)
            board.deletePiece(perm[0],x1,y1)
        
    return bestMove

def playGame(board):
    while True:
        pieces = [PIECEMANAGER.getRandomPiece() for _ in range(3)]
        bestMove = getBestMove(board, pieces)
        
        for move in bestMove:
            board.placePiece(move[0],move[1],move[2], countPoints = True)
        
        board.printBoard()
        print(board.points)
        return

def main():
    gameBoard = Board(6,6)
    
    playGame(gameBoard)
    
if __name__ == "__main__":
    main()