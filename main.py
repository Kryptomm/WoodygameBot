import readImageData as rid
import communicator as com
import tiles as t

def main():
    #Nachher alles in einen Loop
    board = rid.getBoardFromScreen()
    tiles = [t.tiles[0], t.tiles[15], t.tiles[13]]#rid.getTiles()
    
    bestMove = com.getBestMove(board, tiles)

if __name__ == "__main__":
    from time import sleep
    #sleep(3)
    main()