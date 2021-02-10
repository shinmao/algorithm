/**
 * 階層本身有單調性：某階層之前雞蛋都不會破，之後雞蛋就會破
 * 因此可以用binary search
 */
class Solution {
public:
    int dp(int k, int n, vector<vector<int>>& memo) {
        if(n == 0 || n == 1)
            return n;
        
        if(k == 1)
            return n;
        
        if(memo[k][n] != -1)
            return memo[k][n];
        
        int res = INT_MAX;
        int tmp = 0;
        int l = 1, r = n;
        while(l <= n) {
            int m = l + (r - l)/2;
            // 蛋沒破的話，我們知道搜索區間至少是m階以上
            int left = dp(k - 1, m - 1, memo);
            // 蛋破的話，我們知道至少要從m階往下找
            int right = dp(k, n - m, memo);
            // 至少需要的move數 + 當前這次
            tmp = max(left, right) + 1;
            if(left < right) {
                l = m + 1;
            }else {
                r = m - 1;
            }
            res = min(res, tmp);
        }
        
        return memo[k][n] = res;
    }
};

class Solution {
public:
    int superEggDrop(int k, int n) {
                if(n == 0 || n == 1)
            return n;
        if(k == 1)
            return n;
        
        // dp[i][j]: 前i個雞蛋 前j個階梯 測試出破雞蛋的最少move數
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        
        // base case for k = 1
        for(int i = 0; i <= n; i++)
            dp[1][i] = i;
        
        // base case for n = 1
        for(int i = 0; i <= k; i++)
            dp[i][1] = 1;
        
        for(int i = 2; i <= k; i++) {
            for(int j = 2; j <= n; j++) {
                int l = 1, r = j;
                int tmp = 0, res = INT_MAX;
                while(l <= r) {
                    int m = l + (r - l)/2;
                    // 蛋破了，少一顆蛋(i - 1)，之前右區間已經包括了m，因此往下找從(m - 1)開始
                    int left = dp[i - 1][m - 1];
                    // 蛋沒破，因此蛋數量還是(i)，之前左區間已經包括了m，因此往上找從(m + 1)開始
                    int right = dp[i][j - m];
                    tmp = max(left, right) + 1;
                    if(left < right)
                        l = m + 1;
                    else
                        r = m - 1;
                    res = min(res, tmp);
                }
                dp[i][j] = res;
            }
        }
        
        return dp[k][n];
    }
};