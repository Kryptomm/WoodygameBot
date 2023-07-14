import readImageData as rid
import communicator as com
import tiles as t
import move
import defines

from time import sleep

def main():
    while(True):
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
            
            tile = t.getTile(int(m[0]))
            print(f"{tile} to {int(m[1])},{int(m[2])}")
            move.moveTileToCoordinates(tile, invSlot, int(m[1]), int(m[2]))
        sleep(defines.TIME_AFTER_TURN)

if __name__ == "__main__":
    sleep(3)
    print("Starte")
    main()