from collections import deque


def numIslands(grid):
    num = 0
    R = len(grid)
    C = len(grid[0])
    oneQue = deque()
    zeroQue = deque()
    visited = {(0, 0)}
    if grid[0][0] == "1":
        oneQue.append((0, 0))
    else:
        zeroQue.append((0, 0))
    while oneQue or zeroQue:
        while oneQue:
            r, c = oneQue.pop()
            if r + 1 < R:
                visited.add((r + 1, c))
                if grid[r + 1][c] == "1":
                    oneQue.append((r + 1, c))
                else:
                    zeroQue.append((r + 1, c))
            if c + 1 < C:
                visited.add((r, c + 1))
                if grid[r][c + 1] == "1":
                    oneQue.append((r, c + 1))
                else:
                    zeroQue.append((r, c + 1))
        num += 1  # oneQue ended = current island is explored
        while zeroQue:
            r, c = zeroQue.pop()
            if r + 1 < R:
                visited.add((r + 1, c))
                if grid[r + 1][c] == "1":
                    oneQue.append((r + 1, c))
                else:
                    zeroQue.append((r + 1, c))
            if c + 1 < C:
                visited.add((r, c + 1))
                if grid[r][c + 1] == "1":
                    oneQue.append((r, c + 1))
                else:
                    zeroQue.append((r, c + 1))
    return num


grid = [
    ["1", "1", "0", "0", "0"],
    ["1", "1", "0", "0", "0"],
    ["0", "0", "1", "0", "0"],
    ["0", "0", "0", "1", "1"],
]

print(numIslands(grid))
