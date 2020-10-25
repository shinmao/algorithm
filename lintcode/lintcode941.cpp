/**
 * 這裏visited裡面保存的是地圖的狀態
 * 我看到input size很小時就有在考慮狀態壓縮了
 * 只是沒想到他這裡用string的方式來保存地圖狀態
 * queue裡面保存的也是地圖的狀態
 * 還有當初漏看了題意：move是由0和隔壁的元素交換
 * 所以我們只要找出0的位置然後跟隔壁的位置交換即可
 * library function這方面都蠻齊全的
 **/
class Solution {
public:
    /**
     * @param board: the given board
     * @return:  the least number of moves required so that the state of the board is solved
     */
    string hash(vector<vector<int>> &board) {
        string res = "";
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                res += to_string(board[i][j]);
            }
        }
        return res;
    }
    
    bool isValid(int x, int y) {
        if(x < 0 || y < 0 || x >= 2 || y >= 3)
            return false;
        return true;
    }
    
    vector<string> getNxtStatus(string &cur) {
        vector<string> res;
        int zero = cur.find("0");
        int x = zero / 3;
        int y = zero % 3;
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(auto dir: dirs) {
            int nxtX = x + dir[0];
            int nxtY = y + dir[1];
            if(!isValid(nxtX, nxtY))
                continue;
            int newZero = nxtX*3 + nxtY;
            swap(cur[zero], cur[newZero]);
            res.push_back(cur);
            swap(cur[zero], cur[newZero]);
        }
        return res;
    }
    
    int slidingPuzzle(vector<vector<int>> &board) {
        string start = hash(board);
        string end = "123450";
        
        unordered_set<string> visited;
        queue<string> q;
        
        int steps = 0;
        q.push(start);
        visited.insert(start);
        while(!q.empty()) {
            int sz = q.size();
            for(int tmp = 0; tmp < sz; tmp++) {
                string cur = q.front();
                q.pop();
                if(cur == end)
                    return steps;
                for(auto nxtStat : getNxtStatus(cur)) {
                    if(!visited.count(nxtStat)) {
                        visited.insert(nxtStat);
                        q.push(nxtStat);
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};