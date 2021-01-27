/**
 * 需要注意的是dfs的return type
 * 我們只要找到解就回傳答案
 * 所以要用return判別有沒有答案
 */
class Solution {
public:
    bool isValid(vector<vector<char>>& board,
                int row,
                int col,
                char num) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == num)
                return false;
            if(board[i][col] == num)
                return false;
        }
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[row - row%3 + i][col - col%3 + j] == num)
                    return false;
            }
        }
        return true;
    }
    
    bool dfs(vector<vector<char>>& board,
            int row,
            int col) {
        if(row == 9)
            return true;
        
        if(col == 9)
            return dfs(board, row + 1, 0);
        
        if(board[row][col] != '.') 
		    return dfs(board, row, col + 1);

        for(char c = '1'; c <= '9'; c++) {
            if(isValid(board, row, col, c)) {
                board[row][col] = c;
                // 如果這個答案繼續爆破下去是return true代表可行
                // 那就回傳true
                if(dfs(board, row, col + 1))
                    return true;
                board[row][col] = '.';
            }
        }
        // 上面爆破都沒有return 那就return false
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
    }
};