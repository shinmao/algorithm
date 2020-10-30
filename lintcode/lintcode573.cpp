/** 這題如果由每個空地下去BFS找房子會TLE，因為空地可能遠多於房子
 * 所以反過來從房子的角度去訪問空地
**/
class Solution {
private:
    vector<int> dirx = {1, -1, 0, 0};
    vector<int> diry = {0, 0, 1, -1};
    vector<pair<int, int>> empties;
    vector<pair<int, int>> houses;
    // 先拿到每個空地和房子的座標
    void getPosition(vector<vector<int>> &grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    // empty
                    empties.push_back({i, j});
                }else if(grid[i][j] == 1) {
                    // house
                    houses.push_back({i, j});
                }
            }
        }
    }
    
    bool isValid(vector<vector<int>> &grid, int x, int y) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
            return false;
        return true;
    }
    
    void bfs(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &dist, vector<vector<int>> &visitedCnt) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        q.push({x, y});
        visited[x][y] = true;
        
        int steps = 0;
        // visit empty from each houses
        // 訪問整張地圖的過程中更新到每個空地的距離
        while(!q.empty()) {
            int size = q.size();
            steps++;
            for(int tmp = 0; tmp < size; tmp++) {
                int curx = q.front().first;
                int cury = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int nxtX = curx + dirx[i];
                    int nxtY = cury + diry[i];
                    if(!isValid(grid, nxtX, nxtY) || visited[nxtX][nxtY] || grid[nxtX][nxtY] != 0)
                        continue;
                    visited[nxtX][nxtY] = true;
                    visitedCnt[nxtX][nxtY]++;
                    dist[nxtX][nxtY] += steps;
                    q.push({nxtX, nxtY});
                }
            }
        }
    }
public:
    int shortestDistance(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0)
            return -1;
        
        vector<vector<int>> dist(m, vector<int>(n, 0));
        vector<vector<int>> visitedCnt(m, vector<int>(n, 0));
        
        getPosition(grid);
        
        for(auto house : houses) {
            bfs(grid, house.first, house.second, dist, visitedCnt);
        }
        
        int res = INT_MAX;
        // 看每個空地
        // 因為之前是從房子訪問空地
        // 如果被訪問次數等於房子總數代表他可以到達所有房子
        // 更新最短距離
        for(auto empty : empties) {
            int x = empty.first;
            int y = empty.second;
            if(visitedCnt[x][y] == houses.size()) {
                res = min(res, dist[x][y]);
            }
        }
        
        return res == INT_MAX ? -1 : res;
    }
};