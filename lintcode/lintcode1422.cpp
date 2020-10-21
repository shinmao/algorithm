class Solution {
public:
    /**
     * visited裡面記載的是圖上的狀態
     * 這裡我們要避免重複的是圖上的狀態
     * 還好只有12bits，還可以壓縮成二進位
     */
    int shortestPathLength(vector<vector<int>> &graph) {
        if(graph.size() == 1) return 0;
        int n = graph.size();
        // n 位全部為1代表全部都visited
        int finished = (1 << n) - 1;
        
        // <當前node, 圖上visited狀態用binary表示>
        // 1 << i: 除了當前節點，其他皆為0
        queue<pair<int, int>> q;
            
        // n條路徑，每條路徑皆有(1 << n)種遍歷狀態
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
        
        for(int i = 0; i < n; i++) {
            q.push({i, 1 << i});
            visited[i][1 << i] = true;
        }
        
        int dist = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int tmp = 0; tmp < sz; tmp++) {
                auto cur = q.front();
                q.pop();
                int node = cur.first;
                int vis = cur.second;
                // 檢查當前狀態
                if(vis == finished)
                    return dist;
                for(auto neighbor : graph[node]) {
                    // 若當前狀態已經重複
                    if(visited[neighbor][vis])
                        continue;
                    visited[neighbor][vis] = true;
                    q.push({ neighbor, vis | (1 << neighbor) });
                }
            }
            dist++;
        }
        
        return -1;
    }
};