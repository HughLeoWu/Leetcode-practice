'''
    in order to implementing it in-place, we need to define 4 rules, and then we can follow these rules to assign the correct value in the matrix: 
    
    according to these rules 
    1. Any live cell with fewer than two live neighbors dies as if caused by under-population.  
    2. Any live cell with two or three live neighbors lives on to the next generation.  
    3. Any live cell with more than three live neighbors dies, as if by over-population.  
    4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

    when the value needs to be updated, we donot just change  0 to 1 / 1 to 0 but we do in increments and decrements of 2. (table explains)        
      ##   previous value | state change | current state | current value
      ##   0                no change      dead            0
      ##   1                no change      live            1
      ##   0                changed (+2)   live            2
      ##   1                changed (-2)   dead           -1

    ex: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
      (0,0) -> dead, so we just check process the dead condition, and its neighbors are only 1 live cell so it shouldn't be changed 
      (0,1) -> live, there are only 1 live neighbor, so it should be change to 0 "dead", and we remark to -1
      (0,2) -> dead, there are 2 lives neighbors, but it is dead cell, so it shouldn't be changed
      ...
      (3,2) -> dead, there are 3 lives neighbors, so it should be changed and we mark to 2

    after these remark and we re-iteriate this matrix, if the value is larger equal than 1, we will re-assign it to "1" otherwise to "0"  
    
	  ##  TIME COMPLEXITY : O(MxN) ##
	  ##  SPACE COMPLEXITY : O(1) ##
'''
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        directions = [(1,0), (1,-1), (0,-1), (-1,-1), (-1,0), (-1,1), (0,1), (1,1)]
        row, col = len(board), len(board[0])
        for i in range(row):
            for j in range(col):
                live = 0                # live neighbors count
                for x, y in directions: # check and count neighbors in all directions
                    if (i + x < row and i + x >= 0) and (j + y < col and j + y >= 0) and abs(board[i + x][j + y]) == 1:
                        live += 1
                        # (0,0) -> to search (0,1), (1,1), (0,1) => live = 1 (no change)
                        # (0,1) -> (0,0) = 0, (0,2), (1,0), (1,1), (1,2) => live = 1 -> (changed) -1 # rule 4
                        # (0,2) -> (0,1) = -1, (1,1), (1,2) => lives = 2 -> (no change) because lives aren't equal = 3  
                if board[i][j] == 1 and (live < 2 or live > 3):     # Rule 1 or Rule 3
                    board[i][j] = -1
                if board[i][j] == 0 and live == 3:                  # Rule 4
                    board[i][j] = 2
        for i in range(row):
            for j in range(col): 
                # if board[i][j] > 0 => board[i][j] = 1 else => board[i][j] = 0
                board[i][j] = 1 if(board[i][j] > 0) else 0 