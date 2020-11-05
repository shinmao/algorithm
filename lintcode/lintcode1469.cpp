class Solution {
public:
    /**
     * 求樹上最大直徑
     * 解題思路參考geeksforgeeks: https://www.geeksforgeeks.org/longest-path-undirected-tree/
     * 主要是兩次BFS
     * 第一次是由樹上隨便一點出發找最遠的點
     * 第二次是由第一次最遠的點再去找離他最遠的點
     * 那第二次最遠的距離就是樹上最大直徑
     */
    pair<int, int> bfs(unordered_map<int, vector<pair<int, int>>> &treenodes, int root, vector<int> &dist) {
        cout << "root: " << root << '\n';
        queue<int> q;
        q.push(root);
        
        dist[root] = 0;
        
        while(!q.empty()) {
            int head = q.front();
            q.pop();
            for(auto it : treenodes[head]) {
                int neighbor = it.first;
                int len = it.second;
                if(dist[neighbor] == -1) {
                    // still not visit before
                    q.push(neighbor);
                    dist[neighbor] = dist[head] + len;
                }
            }
        }
        
        int maxnode, maxdist = INT_MIN;
        for(int i = 0; i < dist.size(); i++) {
            cout << i << ": " << dist[i] << '\n';
            if(dist[i] > maxdist) {
                maxdist = dist[i];
                maxnode = i;
            }
        }
        
        cout << "maxnode: " << maxnode << ", maxdist: " << maxdist << '\n';
        return make_pair(maxnode, maxdist);
    }
    
    int longestPath(int n, vector<int> &starts, vector<int> &ends, vector<int> &lens) {
        // Write your code here
        if(n == 0 || n == 1)
            return 0;
        
        unordered_map<int, vector<pair<int, int>>> treenodes;
        for(int i = 0; i < starts.size(); i++) {
            treenodes[starts[i]].push_back(make_pair(ends[i], lens[i]));
            treenodes[ends[i]].push_back(make_pair(starts[i], lens[i]));
        }
        vector<int> first_dist(n, -1);
        pair<int, int> t1 = bfs(treenodes, starts[0], first_dist);
        // t1.first is the farest node from starts[0]
        vector<int> second_dist(n, -1);
        pair<int, int> t2 = bfs(treenodes, t1.first, second_dist);
        return t2.second;
    }
};