// 他媽這題真的有夠長
// 還要懂的設計資料結構
// 傳送門也一樣，當edge就好！
class Solution {
public:
    int getMinDistance(vector<vector<int>> &mazeMap) {
        if(mazeMap.size() == 0 || mazeMap[0].size() == 0)
            return -1;
        
        int n = mazeMap.size();
        int m = mazeMap[0].size();
        // 把從起點到該點的距離記錄下來，下次還可以用！
        vector<vector<int>> distance(n, vector<int>(m, 0));
        // 題目說傳送門種類最50種
        // 所以tp[i]對到編碼為i的傳送門
        // 裡面用vector存好幾組編碼為i的座標
        // 座標用pair存
        vector<vector<pair<int, int>>> tp(55);
        // 傳送門用了之後會失效
        vector<bool> tp_visited(55, false);
        vector<int> dirx = {1, -1, 0, 0};
        vector<int> diry = {0, 0, 1, -1};
        
        // find start point and end point
        int beginx, beginy, endx, endy;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int idx = mazeMap[i][j];
                if(idx == -2) {
                    beginx = i; 
                    beginy = j;
                } else if(idx == -3) {
                    endx = i; 
                    endy = j;
                } else if(idx > 0) {
                    tp[idx].push_back(make_pair(i, j));
                    tp_visited[idx] = false;
                }
            }
        }
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push(make_pair(beginx, beginy));
        // visited在入隊的時候就要更新
        visited[beginx][beginy] = true;
        
        while(!q.empty()) {
            pair<int, int> head = q.front();
            q.pop();
            int x = head.first;
            int y = head.second;
            int cost = distance[x][y];
            // arrive!
            // 對當前點的判斷在出隊的時候就要做
            if((x == endx) && (y == endy)) {
                return distance[x][y];
            }
            // go for 4 directions
            for(int i = 0; i < 4; i++) {
                int nextx = x + dirx[i];
                int nexty = y + diry[i];
                // valid?
                if(nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)
                    continue;      // out of bound
                if(mazeMap[nextx][nexty] == -1)
                    continue;      // you cannot go this way
                if(visited[nextx][nexty] == true)
                    continue;      // you already visit here
                visited[nextx][nexty] = true;
                distance[nextx][nexty] = cost + 1;
                q.push(make_pair(nextx, nexty));
            }
            // if we can also deliver
            if(mazeMap[x][y] > 0) {
                if(tp_visited[ mazeMap[x][y] ] == true) {
                    continue;
                }else {
                    // use deliver door
                    for(auto it : tp[mazeMap[x][y]]) {
                        int deliverx = it.first;
                        int delivery = it.second;
                        if(visited[deliverx][delivery] == true)
                            continue;
                        visited[deliverx][delivery] = true;
                        distance[deliverx][delivery] = cost + 1;
                        q.push(make_pair(deliverx, delivery));
                    }
                    // 一樣記得更新visited喔！
                    tp_visited[ mazeMap[x][y] ] = true;
                }
            }
        }
        return -1;
    }
};