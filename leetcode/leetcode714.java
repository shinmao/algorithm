class Solution {
    public int maxProfit(int[] prices, int fee) {
        if(prices == null || prices.length == 1){
            return 0;
        }
        
        int[] buy = new int[prices.length];
        int[] sell = new int[prices.length];
        buy[0] = -prices[0];
        sell[0] = 0;
        
        for(int i = 1; i < prices.length; i++){
            // today hold:
            // 1. yesterday already hold and today do nothing
            // 2. yesterday not hold and today buy
            buy[i] = Math.max(buy[i-1], sell[i-1] - prices[i]);
            // today not hold:
            // 1. yesterday already not hold and today do nothing
            // 2. yesterday buy and today sell and pay for transaction fee
            sell[i] = Math.max(sell[i-1], buy[i-1] + prices[i] - fee);
        }
        
        return sell[prices.length-1];
    }
}