// https://youtu.be/ysro7IPHukk
class Solution {
public:
    /**
     * @param n: the number of servers
     * @param connections: connections
     * @return: Critical Connections in a Network
     * trajan algorithm
     * definition of vector<int> depth is important
     * depth[i] means the minimum depth visited from node i
     * so depth[i] is different from cur_depth
     */
    int dfs(int cur,
            int prev,
            int cur_depth,
            vector<int> &depth,
            vector<vector<int>> &conn,
            vector<vector<int>> &res) {
        // starting from current node
        // return the minimum depth
        depth[cur] = cur_depth + 1;
        for(int neighbor : conn[cur]) {
            // don't go back to the same path
            if(neighbor == prev)
                continue;
                
            if(depth[neighbor] == -1) {
                // still not visited
                // if we visit a node with less depth, then update
                depth[cur] = min(depth[cur], dfs(neighbor, cur, cur_depth + 1, depth, conn, res));
            }else {
                // visited
                depth[cur] = min(depth[cur], depth[neighbor]);
            }
        }
        
        // if the return depth from neighbor is still 
        if(depth[cur] == cur_depth + 1 && cur != 0) {
            if(cur < prev)
                res.push_back({cur, prev});
            else
                res.push_back({prev, cur});
        }
        
        return depth[cur];
    } 
     
    vector<vector<int>> criticalConnectionsinaNetwork(int n, vector<vector<int>> &connections) {
        // write your code here
        vector<vector<int>> res;
        if(n == 1) 
            return {{0, 1}};
            
        vector<vector<int>> conn(n, vector<int>());
        for(auto i : connections) {
            conn[i[0]].push_back(i[1]);
            conn[i[1]].push_back(i[0]);
        }
        
        vector<int> depth(n, -1);
        dfs(0, -1, -1, depth, conn, res);
        
        for(auto i : depth) {
            cout << i << '\n';
        }
        
        return res;
    }
};