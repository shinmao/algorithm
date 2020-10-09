class Solution {
public:
    int numsofIsland(vector<vector<bool>> &grid, int k) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int count = 0;
        for(int i = 0; i < m ; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j]) {
                    if(landsize(grid, visited, i, j) >= k) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
    
    int landsize(vector<vector<bool>> &grid, vector<vector<bool>> &visited, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        
        int size = 0;
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()) {
            int curx = q.front().first;
            int cury = q.front().second;
            q.pop();
            size++;
            for(auto d : dir) {
                int nxtx = curx + d[0];
                int nxty = cury + d[1];
                if(!isValid(grid, visited, nxtx, nxty)) {
                    continue;
                }
                q.push({nxtx, nxty});
                visited[nxtx][nxty] = true;
            }
        }
        return size;
    }
    
    bool isValid(vector<vector<bool>> &grid, vector<vector<bool>> &visited, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return false;
        if(visited[i][j])
            return false;
        if(!grid[i][j])
            return false;
        return true;
    }
};