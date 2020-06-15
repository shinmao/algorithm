// attention: 
// string: "b"
// pattern: "ba*"     result: true
// reason: * matches 0 or >= 1 times of a, so it can match "b", "ba", "baa..."
// attention: in testcase of this problem, * won't appear at the first position
class Solution {
    public boolean isMatch(String s, String p) {
        if (p == null || p.length() == 0) return (s == null || s.length() == 0);
        
        boolean dp[][] = new boolean[s.length()+1][p.length()+1];
        dp[0][0] = true;
        for (int j = 2; j <= p.length(); j++) {
            dp[0][j] = p.charAt(j-1) == '*' && dp[0][j-2]; 
        }
        
        for (int j = 1; j <= p.length(); j++) {
            for (int i = 1; i <= s.length(); i++) {
                if (p.charAt(j-1) == s.charAt(i-1) || p.charAt(j-1) == '.') 
					dp[i][j] = dp[i-1][j-1];
                else if(p.charAt(j-1) == '*')
                    dp[i][j] = dp[i][j-2] || ((s.charAt(i-1) == p.charAt(j-2) || p.charAt(j-2) == '.') && dp[i-1][j]); 
            }
        }
        return dp[s.length()][p.length()];
    }
}

// same idea as wildcard matching
// beats over 100% of submission
class Solution {
    private boolean isEmpty(String p, int pIndex){
        // format such like "x*x*"
        for(int i = pIndex; i < p.length(); i+=2){
            if(i + 1 >= p.length() || p.charAt(i + 1) != '*') return false;
        }
        return true;
    }
    
    private boolean isMatchHelper(String s, int sIndex, String p, int pIndex, boolean[][] memo, boolean[][] visited){
        if(pIndex == p.length()) return sIndex == s.length();
        if(sIndex == s.length()) return isEmpty(p, pIndex);
        if(visited[sIndex][pIndex]) return memo[sIndex][pIndex];
        
        char sChar = s.charAt(sIndex);
        char pChar = p.charAt(pIndex);
        boolean match;
        
        // consider x* as a bundle
        if(pIndex + 1 < p.length() && p.charAt(pIndex + 1) == '*'){
            // '*' matches zero of preceding element
            // '*' matches more of preceding element
            match = isMatchHelper(s, sIndex, p, pIndex+2, memo, visited) ||
                (sChar == pChar || pChar == '.') &&
                isMatchHelper(s, sIndex+1, p, pIndex, memo, visited);
        }else{
            match = (sChar == pChar || pChar == '.') &&
                isMatchHelper(s, sIndex+1, p, pIndex+1, memo, visited);
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