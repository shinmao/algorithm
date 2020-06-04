class Solution {
    public int maxProfit(int[] prices) {
        if(prices == null || prices.length < 2){
            return 0;
        }
        
        // buy[i]: maxprofit for hold on ith day
        int[] buy = new int[prices.length];
        // sell[i]: maxprofit for not hold on ith day
        int[] sell = new int[prices.length];
        
        buy[0] = -prices[0];
        sell[0] = 0;
        
        for(int i = 1; i < prices.length; i++){
            // today hold:
            // 1. yesterday already hold
            // 2. sell two days before and buy today
            buy[i] = Math.max(buy[i-1], (i > 1 ? sell[i-2] : 0) - prices[i]);
            // today not hold:
            // 1. yesterday already not hold
            // 2. yesterday buy and sell today
            sell[i] = Math.max(sell[i-1], buy[i-1] + prices[i]);
        }
        
        return sell[prices.length-1];
    }
}

// In fact, we can reduce space complexity from O(n) to O(1)
// buy[i] is only related to buy[i-1] and sell[i-2]
// sell[i] is only related to sell[i-1] and buy[i-1]
// therefore, we only need three variables to store the previous state