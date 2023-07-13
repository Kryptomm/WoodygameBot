import readImageData as rid
import communicator as com
import tiles as t
import move

def main():
    #Nachher alles in einen Loop
    
    board = rid.getBoardFromScreen()
    tiles = rid.getTiles()
    
    bestMove = com.getBestMove(board, tiles)
    usedItems = []
    print(bestMove)
    
    for m in bestMove:
        invSlot = 1
        for i, it in enumerate(tiles):
            if not i + 1 in usedItems and t.compareTiles(it.grid, t.getTile(int(m[0])).grid):
                invSlot = i + 1
                usedItems.append(i + 1)
                break
        
        move.moveTileToCoordinates(t.getTile(int(m[0])), invSlot, int(m[1]), int(m[2]))

if __name__ == "__main__":
    from time import sleep
    sleep(3)
    print("Starte")
    main()