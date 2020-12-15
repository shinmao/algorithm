class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
            
        /** 這題dp不需要開三維
         * 因為k只能有一次
         * dp[i][0]: i-th day, 沒持有股票的最大利益
         * dp[i][1]: i-th day, 持有股票的最大利益
         * 狀態轉移:
         * dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
         * dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
         * base case:
         * dp[0][0] = 0
         * 注意這裡不是INT_MIN
         * 最多只有一次交易，所以一但持有股票，那一定是-prices[i]
         * dp[0][1] = -prices[i];
        */
        vector<vector<int>> dp(n, vector<int>(2));
        
        for(int i = 0; i < n; ++i) {
            if(i == 0) {
                dp[0][0] = 0;
                dp[0][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], - prices[i]);
        }
        
        return dp[n - 1][0];
    }
};

// 把空間複查度降到O(1)
// 整個dp陣列我們每次其實只用到隔壁那位而已
// 因此用一個變量代替就好
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;

        int no_stock = 0, has_stock = -prices[0];
        
        for(int i = 0; i < n; ++i) {
            no_stock = max(no_stock, has_stock + prices[i]);
            has_stock = max(has_stock, -prices[i]);
        }
        
        return no_stock;
    }
};