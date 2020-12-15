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
            
        /**
         * dp[i][k][0/1]: 在第i天進行第k次交易的最大獲益
         * 0 <= i < n
         * k = 0(x), 1, 2
         */
        vector<vector<vector<int> > > dp(n, vector<vector<int>>(3, vector<int>(2)));
        // base case on 0-th day
        for(int k = 0; k <=2; ++k) {
            dp[0][k][0] = 0;
            dp[0][k][1] = -prices[0];
        }
        // base case on k = 0
        for(int i = 0; i < n; ++i) {
            dp[i][0][0] = 0;
            dp[i][0][1] = INT_MIN;
        }
         
        for(int i = 1; i < n; ++i) {
            for(int k = 1; k <= 2; ++k) {
                // no stock
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                // hold stock
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
            }
        }
        
        return dp[n - 1][2][0];
    }
};

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int n = prices.size();
        if(n == 0)
            return 0;
        
        int buy1 = INT_MIN, buy2 = INT_MIN;
        int sell1 = 0, sell2 = 0;
        
        for(int price : prices) {
            buy1 = max(buy1, -price);
            sell1 = max(sell1, buy1 + price);
            buy2 = max(buy2, sell1 - price);
            sell2 = max(sell2, buy2 + price);
        }
        
        return sell2;
    }
};