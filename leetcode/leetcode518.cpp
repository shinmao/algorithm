class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;
        if(coins.size() == 0)
            return 0;
        
        int n = coins.size();
        /*
        * dp[i][j]: 前i種面額能湊出j的方法數
        * 如果不使用第i種面額：
        * dp[i][j] = dp[i - 1][j]
        * 如果使用第i種面額：
        * dp[i][j] = dp[i - 1][j - coins[i]]
        */
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        
        // base case for i = 0
        for(int j = 0; j <= amount; j++) {
            dp[0][j] = 0;
        }
        
        // base case for j = 0
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                if(j - coins[i - 1] >= 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n][amount];
    }
};
// 看就知道一樣可以狀態壓縮:)
// 不過這邊狀壓不需要改變遍歷順序
// 因為是dp[i][j - coins[i]]而不是dp[i - 1][j - coins[i]]
// 是在同一輪會被更新到的
// 就不需要怕囉！
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;
        if(coins.size() == 0)
            return 0;
        int n = coins.size();
        /*
        * dp[i][j]: 前i種面額能湊出j的方法數
        * 如果不使用第i種面額：
        * dp[i][j] = dp[i - 1][j]
        * 如果使用第i種面額：
        * 為什麼一樣是i呢？
        * 因為第i種面額有無數個
        * 所以前面可能已經選過第i種面額了
        * dp[i][j] = dp[i][j - coins[i]]
        */
        vector<int> dp(amount + 1, 0);

        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= amount; j++) {
                if(j - coins[i] >= 0)
                    dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
        
        return dp[amount];
    }
};