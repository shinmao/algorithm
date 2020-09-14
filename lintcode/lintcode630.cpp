// 先附上一個TLE的做法以作紀念 (雖然手動test case都會過)
// 這裡我把二維的座標用 x*m + y 的概念壓縮成一維
// 用bfs不斷把下一個鄰居放入queue直到queue為空
// 推測是壓縮座標時用了太多時間，所以下面回來用二維座標
vector<vector<int>> jmp = { {1,2},
                            {-1,2},
                            {2,1},
                            {-2,1} };

bool isvalid(int nextx, int nexty, vector<vector<bool>> &grid, 
    unordered_map<int, int> distance) {
    // out of bound?
    if(nextx < 0 || nextx >= grid.size() || 
        nexty < 0 || nexty >= grid[0].size())
        return false;
    // barrier?
    if(grid[nextx][nexty])
        return false;
    // visited?
    if(distance.count(nextx*(grid[0].size()) + nexty))
        return false;
    return true;
}

int shortestPath2(vector<vector<bool>> &grid) {
    if(grid.size() == 0 || grid[0].size() == 0) return -1;
    int n = grid.size(), m = grid[0].size();
    // <x*m + y>
    queue<int> q;
    q.push(0);
    // distance[x*m + y] = distance
    unordered_map<int, int> distance;
    distance[0] = 0;
    while(!q.empty()) {
        int head = q.front();
        q.pop();
        int x = head / m;
        int y = head % m;
        // jump
        for(int i = 0; i < jmp.size(); i++) {
            int nextx = x + jmp[i][0];
            int nexty = y + jmp[i][1];
            if(!isvalid(nextx, nexty, grid, distance)) continue;
            q.push(nextx*m + nexty);
            distance[nextx*m + nexty] = distance[head] + 1;
            if(nextx == n-1 && nexty == m-1)
                return distance[nextx*m + nexty];
        }
    }
    if(distance.count(n*m - 1))
        return distance[n*m - 1];
    return -1;
}

// 我直接把二維座標push到queue裡面
// 可是這樣就沒辦法用map查distance了
// 畢竟沒有這種東西 distance[vector<>(x, y)]
// 就算自己寫個hash那會導致跟上面一樣的結果
// 所以只好用一個distance去更新，並且過程中不斷檢查有沒有到終點了
// 可是這就必須用 分層 的方式去遍歷，不然distance會算錯
// 每一層都是去訪問離當前最近的鄰居(並且同樣距離)，所以每一層訪問完，distance通通+1
// 另外我還創一個visited陣列去檢查有沒有重複訪問
// 有些人會直接去修改grid，可是這在面試中不是一個好習慣～
vector<vector<int>> jmp = { {1,2},
                            {-1,2},
                            {2,1},
                            {-2,1} };

bool isvalid(int nextx, int nexty, 
    vector<vector<bool>> &grid, vector<vector<bool>> &visited) {
    // out of bound?
    if(nextx < 0 || nextx >= grid.size() || 
        nexty < 0 || nexty >= grid[0].size())
        return false;
    // barrier?
    if(grid[nextx][nexty])
        return false;
    if(visited[nextx][nexty])
        return false;
    return true;
}

int shortestPath2(vector<vector<bool>> &grid) {
    if(grid.size() == 0 || grid[0].size() == 0) return -1;
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<vector<int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    int distance = 0;
    while(!q.empty()) {
        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            vector<int> head = q.front();
            q.pop();
            if(head[0] == n-1 && head[1] == m-1)
                return distance;
            for(int i = 0; i < 4; i++) {
                int nextx = head[0] + jmp[i][0];
                int nexty = head[1] + jmp[i][1];
                //cout << nextx << ' ' << nexty << '\n'; 
                if(!isvalid(nextx, nexty, grid, visited))
                    continue;
                q.push({nextx, nexty});
                visited[nextx][nexty] = true;
            }
        }
        distance++;
    }
    return -1;
}