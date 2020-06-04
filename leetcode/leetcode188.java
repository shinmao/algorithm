// Same idea as Best Time to Buy and Sell Stock III
// right answer but Memory Limit Exceeded
// O(nk)
class Solution {
    public int maxProfit(int k, int[] prices) {
        if(prices == null || prices.length == 0 || k == 0){
            return 0;
        }
        
        int[] buy = new int[k + 1];
        int[] sell = new int[k + 1];
        buy[0] = 0;
        for(int i = 1; i <= k; i++){
            buy[i] = Integer.MIN_VALUE;
        }
        sell[0] = 0;
        
        for(int i = 0; i < prices.length; i++){
            for(int j = 1; j <= k; j++){
                // the maxprofit for buying j times
                buy[j] = Math.max(buy[j], sell[j-1] - prices[i]);
                // the maxprofit for selling j times
                sell[j] = Math.max(sell[j], buy[j] + prices[i]);
            }
        }
        
        return sell[k];
    }
}

// I find that Memory Limit Exceeded when k is so large
// However in some case, we can reduce O(nk) to O(n)
// the state of each transaction profit is buy1, sell1, buy2, sell2, ... buyk, sellk
// each state are on different days
// if number of state is bigger than number of days
// that also means number of transaction is not limited
// then problem is back to simple one: just sell it when price increases
class Solution {
    public int maxProfit(int k, int[] prices) {
        if(prices == null || prices.length == 0 || k == 0){
            return 0;
        }
        
        if( k*2 >= prices.length ){
            int profit = 0;
            for(int i = 1; i < prices.length; i++){
                if(prices[i] > prices[i-1]){
                    profit += prices[i] - prices[i-1];
                }
            }
            return profit;
        }
        
        // same
    }
}