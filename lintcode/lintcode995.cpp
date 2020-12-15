class Solution {
public:
    /**
     * @param prices: a list of integers
     * @return: return a integer
     */
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        
        /** 
         * dp[i][0]：第i天未持有股票的最大利益
         * dp[i][1]：第i天持有股票的最大利益
         * 狀態轉移方程
         * dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
         * dp[i][1] = max(dp[i][1], dp[i - 2][0] - prices[i]);
         */ 
        int not_hold = 0, hold = -prices[0], prev_not_hold = 0;
        
        for(int i = 0; i < n; ++i) {
            int tmp = not_hold;
            not_hold = max(not_hold, hold + prices[i]);
            hold = max(hold, prev_not_hold - prices[i]);
            prev_not_hold = tmp;
        }
        
        return not_hold;
    }
};