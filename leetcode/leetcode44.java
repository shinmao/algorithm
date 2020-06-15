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

// DFS + memoization
// memo[i][j]: s[i~m-1] can be matched by p[j~n-1]
// ------i-------- s
// -----j------- p
// if p[j] = a~z or 0-9, s[i] = p[j] && memo[i+1][j+1]
// if p[j] = ?, i < s.length && memo[i+1][j+1]
// if p[j] = *, 
// method 1: enulmerate matched length 0, 1 to n
// (clear) method 2:
// if * means empty string, memo[i][j+1] (i doesn't need to move, j needs to move forward)
// if * means not empty string, memo[i+1][j] (i has been matched so move forward, j stay still)
// 這裡的思路關於 * 匹配非空字串的思路很厲害，i 不管怎樣都會繼續向後匹配，j只要待在原地就好，因為下一個還是可以匹配 *
// beats over 61% of submission
class Solution {
    private boolean allStar(String p, int pIndex){
        // is there only * left
        for(int i = pIndex; i < p.length(); i++){
            if(p.charAt(i) != '*') return false;
        }
        return true;
    }
    
    private boolean isMatchHelper(String s, int sIndex, String p, int pIndex, boolean[][] memo, boolean[][] visited){
        // if there is no pattern left, it is matched only if string is also no left
        if(pIndex == p.length()) return sIndex == s.length();
        // if there is no string left, p can only be * e.g. (ab, ab*)
        if(sIndex == s.length()) return allStar(p, pIndex);
        if(visited[sIndex][pIndex]) return memo[sIndex][pIndex];
        
        char sChar = s.charAt(sIndex);
        char pChar = p.charAt(pIndex);
        boolean match;
        
        if(pChar == '*'){
            // the most important and interesting part
            match = isMatchHelper(s, sIndex, p, pIndex+1, memo, visited) || isMatchHelper(s, sIndex+1, p, pIndex, memo, visited);
        }else{
            match = (sChar == pChar || pChar == '?') && isMatchHelper(s, sIndex+1, p, pIndex+1, memo, visited);
        }
        
        visited[sIndex][pIndex] = true;
        memo[sIndex][pIndex] = match;
        return match;
    }
    
    public boolean isMatch(String s, String p) {
        if(s == null || p == null) return false;
        
        boolean[][] memo = new boolean[s.length()][p.length()];
        boolean[][] visited = new boolean[s.length()][p.length()];
        return isMatchHelper(s, 0, p, 0, memo, visited);
    }
}