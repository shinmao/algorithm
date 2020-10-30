/** 這題不是最短路徑
 * 但也不至於用到dfs
 * 看看我們的條件，我們的target有一個上限
 * 所以可以用binary search猜這個target
 * 然後透過bfs看這個target可不可以到終點
 * 因為target是一條路徑上最大所需的height差
 * 因此如果bfs的路徑上有任一height差大於這個target就代表這個target不可能
**/
class Solution {
private:
    vector<int> dirx = {1, -1, 0, 0};
    vector<int> diry = {0, 0, 1, -1};
    
    bool isValid(vector<vector<int>> &arr, vector<vector<bool>> &visited, int x, int y) {
        int n = arr.size();
        if(x < 0 || y < 0 || x >= n || y >= n) 
            return false;
        if(visited[x][y])
            return false;
        return true;
    }
    
    bool bfs(vector<vector<int>> &arr, int threshold) {
        int n = arr.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        
        while(!q.empty()) {
            int curx = q.front().first;
            int cury = q.front().second;
            q.pop();
            if(curx == n - 1 && cury == n - 1) return true;
            for(int i = 0; i < 4; i++) {
                int nxtX = curx + dirx[i];
                int nxtY = cury + diry[i];
                if(!isValid(arr, visited, nxtX, nxtY))
                    continue;
                if(abs(arr[nxtX][nxtY] - arr[curx][cury]) > threshold)
                    continue;
                
                q.push({nxtX, nxtY});
                visited[nxtX][nxtY] = true;
            }    
        }
        
        return false;
    }
public:
    int mapJump(vector<vector<int>> &arr) {
        int start = 0, end = 100000;
        while(start < end) {
            // 在這裡卡了很久，後面(end-start) >> 1的部分一定要記得括號起來啦 :)
            int mid = start + ((end - start) >> 1);
            if(bfs(arr, mid))
                end = mid;
            else
                start = mid + 1;
        }
        
        return start;
    }
};