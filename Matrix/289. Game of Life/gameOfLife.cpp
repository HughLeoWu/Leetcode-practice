/*
when the value needs to be updated, we donot just change  0 to 1 / 1 to 0 but we do in increments and decrements of 2. (table explains)        
      ##   previous value | state change | current state | current value
      ##   0                no change      dead            0
      ##   1                no change      live            1
      ##   0                changed (+2)   live            2
      ##   1                changed (-2)   dead           -1
*/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size();
        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++) {
                int lives = 0;
                for(int y = r - 1; y <= r + 1; y++) {
                    for(int x = c - 1; x <= c + 1; x++) {
                        if(x == c && y == r)
                            continue;
                        if(x >= 0 && y >= 0 && x < col && y < row && abs(board[y][x]) == 1)
                            lives++;
                    }
                }
                if(board[r][c] == 1 && (lives < 2 || lives > 3))
                    board[r][c] = -1;
                if(board[r][c] == 0 && lives == 3)
                    board[r][c] = 2;
            }
        }
        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++) {
                if(board[r][c] >= 1)
                    board[r][c] = 1;
                else
                    board[r][c] = 0;
            }
        }
    }
};