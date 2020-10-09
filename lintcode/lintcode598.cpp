// 有兩個點要注意：
// 由於我們會改動 grid
// 但是start traverse的point不能變
// 所以我們一開始先遍歷一遍把zombie的位置都先放入queue裡
// 剩下的就都大同小異了
// 另外是day的部分
// 由於題目要回傳的是經過多久而非在第幾天
// 所以這裡要回傳day - 1
// 這裡比較有趣的是先計算好個體的數量
// 最後直接透過個體的數量去檢查是否map中所有people都已變成zombie
class Solution {
public:
    bool isValid(vector<vector<int>> &grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return false;
        if(grid[i][j] != 0)
            return false;
        return true;
    }
    
    int zombie(vector<vector<int>> &grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return -1;
        int m = grid.size();
        int n = grid[0].size();
        
        int day = 0, zombie = 0, wall = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    zombie++;
                    q.push({i, j});
                }else if(grid[i][j] == 2) {
                    wall++;
                }
            }
        }
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()) {
            int lim = q.size();
            for(int tmp = 0; tmp < lim; tmp++) {
                int curx = q.front().first;
                int cury = q.front().second;
                q.pop();
                for(auto dir : dirs) {
                    int nxtx = curx + dir[0];
                    int nxty = cury + dir[1];
                    if(!isValid(grid, nxtx, nxty))
                        continue;
                    q.push({nxtx, nxty});
                    grid[nxtx][nxty] = 1;
                    zombie++;
                }
            }
            day++;
        }
        
        return m*n - zombie - wall == 0 ? day -1 : -1;
    }
};