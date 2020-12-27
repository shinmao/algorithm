class Solution {
public:
    /**
     * @param A: an integer array
     * @param V: an integer array
     * @param m: An integer
     * @return: an array
     */
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        // 完全背包問題
        if(m == 0 || A.size() == 0 || V.size() == 0)
            return 0;
            
        int n = A.size();
        /**
         * dp[i][j]: 前i種物品填滿j的capacity得到的最大價值
         * 如果不放第i種物品
         * dp[i][j] = dp[i - 1][j]
         * 如果放第i種物品
         * dp[i][j] = dp[i][j - A[i - 1]] + V[i - 1]
         */
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // base case for i = 0, dp[0][j] = 0
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(j - A[i - 1] >= 0)
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - A[i - 1]] + V[i - 1]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        
        return dp[n][m];
    }
};
// 一樣狀壓
class Solution {
public:
    /**
     * @param A: an integer array
     * @param V: an integer array
     * @param m: An integer
     * @return: an array
     */
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        // 完全背包問題
        if(m == 0 || A.size() == 0 || V.size() == 0)
            return 0;
            
        int n = A.size();
        /**
         * dp[i][j]: 前i種物品填滿j的capacity得到的最大價值
         * 如果不放第i種物品
         * dp[i][j] = dp[i - 1][j]
         * 如果放第i種物品
         * dp[i][j] = dp[i][j - A[i - 1]] + V[i - 1]
         */
        vector<int> dp(m + 1, 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= m; j++) {
                if(j - A[i] >= 0)
                    dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
            }
        }
        
        return dp[m];
    }
};