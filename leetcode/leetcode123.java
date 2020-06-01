// four state: buy 1nd stock -> sell 1nd stock -> buy 2nd stock -> sell 2nd stock
// profit: -price[i1] -> -prices[i1] + price[i2] -> -prices[i1] + price[i2] - price[i3] -> -prices[i1] + price[i2] - price[i3] + price[i4]
// we want all states of profit to be maximum
class Solution {
    public int maxProfit(int[] prices) {
        if(prices == null || prices.length == 0) return 0;
        int buy1 = Integer.MIN_VALUE, sell1 = 0;
        int buy2 = Integer.MIN_VALUE, sell2 = 0;
        
        for(int i : prices){
            buy1 = Math.max(buy1, -i);
            sell1 = Math.max(sell1, i + buy1);
            buy2 = Math.max(buy2, sell1 - i);
            sell2 = Math.max(sell2, i + buy2);
        }
        
        return sell2;
    }
}