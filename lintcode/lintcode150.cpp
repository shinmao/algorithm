/**
 * 這題我個人覺得我blog上的解法比較好理解
 */ 
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
        
        int profit = 0;
        for(int i = 1; i < n; ++i) {
            if(prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }
        
        return profit;
    }
};