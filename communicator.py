import subprocess

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
    
    #Besten Move berechnen
    command = ["./program", board, tiles.split(" ")[0], tiles.split(" ")[1], tiles.split(" ")[2]]
    process = subprocess.Popen(command)
    process.wait()
    
    #Move auslesen
    with open("outputBestMove", "r") as f:
        txt = f.read().split("\n")
        return [txt[0].split(" "), txt[1].split(" "), txt[2].split(" ")]