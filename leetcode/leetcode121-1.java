class Solution {
    public int maxProfit(int[] prices) {
        if(prices == null || prices.length == 0){
            return 0;
        }
        
        int len = prices.length;
        int max = 0;
        int mp = Integer.MAX_VALUE;
        
        for(int i = 0; i < len; i++){
            if(prices[i] < mp){
                mp = prices[i];
            }
            
            if(prices[i] - mp > max){
                max = prices[i] - mp;
            }
        }
        
        return max;
    }
}