from board import Board
from pieces import Piece, PieceManager

PIECEMANAGER = PieceManager()

def getBestMove(board, pieces):
    return 0

def playGame(board):
    while True:
        pieces = [PIECEMANAGER.getRandomPiece() for _ in range(3)]
        pieces[0].printPiece()
        print()
        pieces[1].printPiece()
        print()
        pieces[2].printPiece()
        return

def main():
    gameBoard = Board(5,5)
    
    playGame(gameBoard)
    
if __name__ == "__main__":
    main()