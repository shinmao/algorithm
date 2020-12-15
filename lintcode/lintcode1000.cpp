class Solution {
public:
    /**
     * @param prices: a list of integers
     * @param fee: a integer
     * @return: return a integer
     */
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        if(n <= 1 || fee <= 0)
            return 0;
            
        /**
         * 狀態轉移方程
         * pay fee on selling
         * dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
         * dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
         * 一樣是跟鄰居作業而已 不需要整個dp陣列
         */ 
        int not_hold = 0, hold = -prices[0];
        
        for(int i = 0; i < n; ++i) {
            int tmp = not_hold;
            not_hold = max(not_hold, hold + prices[i] - fee);
            // 注意前面not_hold已經被動過了，所以我先用一個變量把前一天的not_hold存起來
            hold = max(hold, tmp - prices[i]);
        }
        
        return not_hold;
    }
};