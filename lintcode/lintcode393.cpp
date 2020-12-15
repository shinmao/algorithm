class Solution {
public:
    /**
     * k太大，dp陣列開太大導致內存爆開
     */ 
    int maxProfit(int K, vector<int> &prices) {
        // write your code here
        int n = prices.size();
        if(K > n/2) {
            int maxprofit = 0;
            // 我們每天都可以進行交易
            // 相當於交易次數沒有限制
            for(int i = 1; i < n; ++i) {
                if(prices[i] > prices[i - 1])
                    maxprofit += prices[i] - prices[i - 1];
            }
            
            return maxprofit;
        }
        
        // 昨天就持有，或今天買的
        // dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
        // 昨天就沒有，或今天賣掉的
        // dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(K + 1, vector<int>(2)));
        
        for(int k = 0; k <= K; ++k) {
            // base case for 0-th day
            dp[0][k][0] = 0;
            dp[0][k][1] = -prices[0];
        }
        
        for(int i = 0; i < n; ++i) {
            // base case for k = 0
            dp[i][0][0] = 0;
            dp[i][0][1] = INT_MIN;
        }
        
        for(int i = 1; i < n; ++i) {
            for(int k = 1; k <= K; ++k) {
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
            }
        }
        
        return dp[n - 1][K][0];
    }
};