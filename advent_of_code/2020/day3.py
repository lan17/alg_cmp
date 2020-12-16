from functools import reduce
from typing import List


def solve1(board:List[str], dy=3, dx=1):
    x = 0
    y = 0
    cnt = 0
    while y < len(board):
        if board[y][x] == '#':
            cnt += 1
        x += dx
        y += dy
    return cnt



def main():
    with open('day3.in') as file:
        board = []
        for line in file.readlines():
            board.append(line.strip())
        num_rows = len(board)
        for i in range(num_rows):
            board[i] = board[i] * num_rows

        # print(board)
        print(solve1(board))

        slope_tree_counts = [solve1(board, 1, 1), solve1(board, 1, 3), solve1(board, 1, 5), solve1(board, 1, 7), solve1(board, 2, 1)]
        print(reduce(lambda accum, val: accum * val, slope_tree_counts, 1))




if __name__ == '__main__':
    main()