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

// 點子跟上一個 solution 非常相似
// 都是將之前前i個的可行結果保留下來
// 我認為優化的地方在於for loop的內層
// 上面最糟的情況下會將i個length都枚舉出來
// 這裏排除了枚舉超過字典中的最長長度(不可能出現的segmentation case)
// beats over 98% of submission
class Solution {
    // get the longest length in dict
    private int getMaxLength(List<String> dict){
        int maxLength = 0;
        for(String word : dict){
            maxLength = Math.max(maxLength, word.length());
        }
        return maxLength;
    }
    
    public boolean wordBreak(String s, List<String> wordDict) {
        if(s.length() == 0) return true;
        
        int maxLength = getMaxLength(wordDict);
        // canSegment[i]: 0 to index i can be segment or not
        boolean[] canSegment = new boolean[s.length() + 1];
        
        // cal order: canSegment[i = 0->1->2->3...i->...n]
        canSegment[0] = true;
        for(int i = 1; i <= s.length(); i++){
            // enumerate dict word with length
            for(int lastWordLength = 1;
                    lastWordLength <= maxLength && lastWordLength <= i;
                    lastWordLength++){
                // so we already know canSegment[i-word] here
                if(!canSegment[i-lastWordLength]) continue;
                String word = s.substring(i-lastWordLength, i);
                if(wordDict.contains(word)){
                    canSegment[i] = true;
                    break;
                }
            }
        }
        
        return canSegment[s.length()];
    }
}