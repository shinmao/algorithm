// attention: wordDict doesn't need to use all of its words
// this solution is brute force with dfs
// this would cause to TLE but build up the idea of DP
class Solution {
    public boolean dfs(String s, List<String> dict, int start){
        if(start == s.length()){
            return true;
        }
        
        // len: length of tested word
        for(int len = 1; start + len <= s.length(); len++){
            if(dict.contains(s.substring(start, start + len)) && dfs(s, dict, start + len)) return true;
        }
        
        return false;
    }
    
    public boolean wordBreak(String s, List<String> wordDict) {
        if(s.length() == 0 || wordDict.size() == 0) return false;
        
        return dfs(s, wordDict, 0);
    }
}

// DP
// beats only over 39% of submission
// already known to be mapped | word contained in dict
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        if(s == null || wordDict == null || s.length() == 0 || wordDict.size() == 0) return false;
        
        // dp[i]: result for subarray(0, i)
        boolean[] dp = new boolean[s.length()+1];
        dp[0] = true;
        
        for(int i = 1; i <= s.length(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && wordDict.contains(s.substring(j, i))){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.length()];
    }
}