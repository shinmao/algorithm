/**
 * 思路很簡單：兩次bfs，先找到狗，再離開lake
 * 比較特殊的地方是這題有滑行的移動方式
 * 稍微注意一下for迴圈的細節
 * 有空的話來研究一下雙狀態bfs吧，可以壓縮到一個迴圈就好
 * https://blog.csdn.net/roufoo/article/details/106601949
 **/
class Solution {
private:
    vector<int> dirx = {1, -1, 0, 0};
    vector<int> diry = {0, 0, 1, -1};
    bool inbnd(vector<vector<int>> &l, int x, int y) {
        if(x < 0 || y < 0 || x >= l.size() || y >= l[0].size())
            return false;
        return true;
    }
    
    bool take_kuna(vector<vector<int>> &l, vector<vector<bool>> &v, int ax, int ay, int kx, int ky) {
        queue<pair<int, int>> q;
        q.push({ax, ay});
        v[ax][ay] = true;
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x == kx && y == ky)
                return true;
            for(int i = 0; i < 4; i++) {
                /**
                 * 為何這邊是以<x, y>而不是<x + dirx[i], y + diry[i]>?
                 * 因為有兩種可能，若下一個位置是1，那就跟普通的bfs一樣
                 * 若下一個位置是0，那就會一路滑下去，直到碰到1，那麼就會出來變普通bfs; 碰到-1，則直接前途全毀
                 **/ 
                int nxtX = x, nxtY = y;
                while((nxtX == x && nxtY == y) || (inbnd(l, nxtX, nxtY) && l[nxtX][nxtY] != 1)) {
                    nxtX += dirx[i];
                    nxtY += diry[i];
                    if(inbnd(l, nxtX, nxtY) && l[nxtX][nxtY] == -1)
                        break;    
                }
                if(inbnd(l, nxtX, nxtY) && l[nxtX][nxtY] == 1 && !v[nxtX][nxtY]){
                    q.push({nxtX, nxtY});
                    v[nxtX][nxtY] = true;
                }
            }
        }
        
        return false;
    }

/** 這邊就是兩種離開lake的方法
 * 一種就是走到lake邊，若是0一定可以滑出去，若是1，則靠bfs走出去
 * 另一種就是滑行的過程就直接滑出去了
 **/ 
    bool reach_bank(vector<vector<int>> &l, vector<vector<bool>> &v, int kx, int ky) {
        queue<pair<int, int>> q;
        q.push({kx, ky});
        v[kx][ky] = true;
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if((x == 0 || x == l.size() - 1 || y == 0 || y == l[0].size() - 1) && l[x][y] == 0)
                return true;
            for(int i = 0; i < 4; i++) {
                int nxtX = x, nxtY = y;
                while((nxtX == x && nxtY == y) || (inbnd(l, nxtX, nxtY) && l[nxtX][nxtY] != 1)) {
                    nxtX += dirx[i];
                    nxtY += diry[i];
                    if((nxtX == 0 || nxtX == l.size() - 1 || nxtX == 0 || nxtY == l[0].size() - 1) && l[nxtX][nxtY] == 0)
                        return true;
                    if(inbnd(l, nxtX, nxtY) && l[nxtX][nxtY] == -1)
                        break;
                }
                if(inbnd(l, nxtX, nxtY) && l[nxtX][nxtY] == 1 && !v[nxtX][nxtY]) {
                    q.push({nxtX, nxtY});
                    v[nxtX][nxtY] = true;
                }
            }
        }
        
        return false;
    }
public:
    bool lakeEscape(int side_length, vector<vector<int>> &lake_grid, int albert_row, int albert_column, int kuna_row, int kuna_column) {
        vector<vector<bool>> visited(lake_grid.size(), vector<bool>(lake_grid[0].size(), false));
        vector<vector<bool>> visited_(lake_grid.size(), vector<bool>(lake_grid[0].size(), false));
        return take_kuna(lake_grid, visited, albert_row, albert_column, kuna_row, kuna_column) && reach_bank(lake_grid, visited_, kuna_row, kuna_column);
    }
};