import defines
import tiles as til

def compare_2d_arrays(arr1, arr2):
    if len(arr1) != len(arr2):
        return False

    for i in range(len(arr1)):
        if len(arr1[i]) != len(arr2[i]):
            return False

        for j in range(len(arr1[i])):
            if arr1[i][j] != arr2[i][j]:
                return False

    return True


def getBoardString(board):
    txt = ""
    for y in range(0, defines.BOARD_HEIGHT):
        for x in range(0, defines.BOARD_WIDTH):
            txt += str(board[y][x])
    return txt

def getTilesString(tiles):
    txt = ""
    for t in tiles:
        for i,st in enumerate(til.tiles):
            if t.grid == st.grid:
                txt += str(i) + " "
    
    return txt.strip()

def getBestMove(board, tiles):
    #board und tiles in strings decoden
    board = getBoardString(board)
    tiles = getTilesString(tiles)
    
    print(board, tiles)
    
    return None