// DP + DFS
// I cannot use DP to directly solve this problem
// but use DP to help isPalindrome()
// beats 100% of submission
class Solution {
    private boolean isPalindrome(String s, int head, int tail, boolean[][] dp){
        while(head < tail){
            if(dp[head][tail]){
                break;
            }
            if(s.charAt(head) != s.charAt(tail)){
                return false;
            }
            head++;
            tail--;
        }
        return true;
    }
    private void helper(String s, List<List<String>> result, List<String> sub, boolean[][] dp, int start){
        if(start == s.length()){
            result.add(new ArrayList<String>(sub));
            return;
        }
        for(int i = start; i < s.length(); i++){
            if(dp[start][i]){
                sub.add(s.substring(start, i+1));
                helper(s, result, sub, dp, i+1);
                // reset sub when start on new loop
                sub.remove(sub.size() - 1);
            }
        }
    }
    public List<List<String>> partition(String s) {
        List<List<String>> result = new ArrayList<>();
        if(s == null || s.length() == 0){
            result.add(new ArrayList<>());
            return result;
        }
        
        int n = s.length();
        // dp[i][j]: string from i to j is palindrome or not
        boolean[][] dp = new boolean[n][n];
        
        // every char of string is palindrome
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        
        // length two: palindrome if two chars are same
        for(int i = 0; i < n-1; i++){
            if(s.charAt(i) == s.charAt(i+1)){
                dp[i][i+1] = true;
            }else{
                dp[i][i+1] = false;
            }
        }
        
        for(int i = 0; i < n-2; i++){
            for(int j = i+2; j < n; j++){
                dp[i][j] = isPalindrome(s, i, j, dp);
            }
        }
        
        helper(s, result, new ArrayList<String>(), dp, 0);
        
        return result;
    }
}