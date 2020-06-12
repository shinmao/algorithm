// s: 0, 1, ... i-1, i
// p: 0, 1, ...j-1, j
// beats only over 13% of submission
class Solution {
    public boolean isMatch(String s, String p) {
        if(s == null || p == null) return false;
        
        int str_len = s.length();
        int ptr_len = p.length();
        // dp[i][j]: the matched result of first i chars of string and first j chars of pattern
        boolean[][] dp = new boolean[str_len+1][ptr_len+1];
        
        dp[0][0] = true;  // empty seq matches to empty seq
        for(int i = 1; i <= str_len; i++){
            dp[i][0] = false;
        }
        for(int j = 1; j <= ptr_len; j++){
            if(p.charAt(j-1) == '*'){
                dp[0][j] = dp[0][j-1];
            }
        }
        
        for(int i = 1; i <= str_len; i++){
            for(int j = 1; j <= ptr_len; j++){
                dp[i][j] = false;
                char str = s.charAt(i-1);
                char ptr = p.charAt(j-1);
                switch(ptr){
                    case '*':
                        // if p[j] is *
                        // 1. if before is already matched, * matched one character
                        // 2. if first i chars matched to first (j-1) chars, * matched empty sequence
                        // 3. if first (i-1) chars matched to first j chars, next char would also be matched to *
                        if(dp[i-1][j-1] == true || dp[i][j-1] == true || dp[i-1][j] == true) dp[i][j] = true;
                        break;
                    case '?':
                        // if p[j] is ?
                        // if before is already matchedand current character is also matched
                        if(dp[i-1][j-1] == true) dp[i][j] = true;
                        break;
                    default:
                        // if p[j] is character
                        // if before is already matched and current character is also matched
                        if(dp[i-1][j-1] == true && str == ptr) dp[i][j] = true;
                        break;
                }
            }
        }
        
        return dp[str_len][ptr_len];
    }
}