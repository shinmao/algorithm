class Solution {
public:
    bool isValid(vector<vector<char>>& grid, vector<vector<bool>> &visited, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return false;
        if(visited[i][j])
            return false;
        if(grid[i][j] == '0')
            return false;
        return true;
    }
    
    void bfs(vector<vector<char>>& grid, vector<vector<bool>> &visited, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()) {
            int curx = q.front().first;
            int cury = q.front().second;
            q.pop();
            for(auto dir : dirs) {
                int nxtx = curx + dir[0];
                int nxty = cury + dir[1];
                if(!isValid(grid, visited, nxtx, nxty))
                    continue;
                q.push({nxtx, nxty});
                visited[nxtx][nxty] = true;
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    bfs(grid, visited, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};