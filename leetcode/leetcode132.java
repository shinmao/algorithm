// beats only over 35% of submission
class Solution {
    private boolean[][] getIsPalindrome(String s){
        boolean[][] isPalindrome = new boolean[s.length()][s.length()];
        for(int i = 0; i < s.length(); i++) isPalindrome[i][i] = true;
        for(int i = 0; i < s.length()-1; i++) isPalindrome[i][i+1] = (s.charAt(i) == s.charAt(i+1));
        for(int length = 2; length < s.length(); length++){
            for(int start = 0; start + length < s.length(); start++){
                isPalindrome[start][start+length] = isPalindrome[start+1][start+length-1] && s.charAt(start) == s.charAt(start+length);
            }
        }
        
        return isPalindrome;
    }
    
    public int minCut(String s) {
        // memo[i]: at least how many palindrome ends at index (i-1)
        // | memo[j] | palindrome  |
        //           j             i  
        // memo[i] = min(1 + memo[j]), s[j~i] is palindrome
        if(s == null || s.length() == 0) return 0;
        
        boolean[][] isPalindrome = getIsPalindrome(s);
        int[] memo = new int[s.length()+1];
        memo[0] = 0;
        
        for(int i = 1; i <= s.length(); i++){
            memo[i] = Integer.MAX_VALUE;
            for(int j = 0; j < i; j++){
                if(isPalindrome[j][i-1]){
                    memo[i] = Math.min(memo[i], memo[j] + 1);
                }
            }
        }
        
        // we want the cuts instead of number of palindrome
        return memo[s.length()] - 1;
    }
}