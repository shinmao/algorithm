/**
 * 重要思路：
 * for any index >= 0 and < len(string)
 * 左括號數一定大於或等於右括號數
*/
class Solution {
public:
    // l means the left number of left parentheses
    // r means the left number of right parentheses
    void dfs(int l, int r, string par, vector<string>& res) {
        if(l > r)
            return;
        if(l < 0 || r < 0)
            return;
        if(l == 0 && r == 0) {
            // all of parentheses have been used off
            res.push_back(par);
            return;
        }
        
        // if I use "("
        par.push_back('(');
        dfs(l - 1, r, par, res);
        par.pop_back();
        
        // if I use ")"
        par.push_back(')');
        dfs(l, r - 1, par, res);
        par.pop_back();
    }
    
    vector<string> generateParenthesis(int n) {
        if(n == 1)
            return vector<string>(1, "()");
        
        vector<string> res;
        string par;
        dfs(n, n, par, res);
        return res;
    }
};