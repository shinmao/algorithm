/**
 * 思路：backtrack
 */
class Solution {
public:
    void dfs(int n,
            int k,
            int start,
            vector<int> r,
            vector<vector<int>>& res) {
        if(r.size() == k) {
            res.push_back(r);
            return;
        }
        
        for(int i = start; i <= n; i++) {
            r.push_back(i);
            dfs(n, k, i + 1, r, res);
            r.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        if(n <= 0 || k <= 0)
            return {{}};
        
        vector<int> r;
        vector<vector<int>> res;
        dfs(n, k, 1, r, res);
        
        return res;
    }
};