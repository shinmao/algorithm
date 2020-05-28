class Solution {
    public int longestPalindromeSubseq(String s) {
        if(s == null || s.length() == 0){
            return 0;
        }
        
        int max = 1;
        int size = s.length();
        char[] c = s.toCharArray();
        int[][] dp = new int[size][size];
        
        for(int i = size-1; i >= 0; i--){
            dp[i][i] = 1;
            for(int j = i+1; j < size; j++){
                if(c[i] == c[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }else{
                    dp[i][j] = Math.max(dp[i][j-1], dp[i+1][j]);
                }
                
                if(dp[i][j] > max){
                    max = dp[i][j];
                }
            }
        }
        
        return max;
    }
}