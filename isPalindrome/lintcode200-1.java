public class Solution {
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    public String longestPalindrome(String s) {
        // exception
        if(s == null || s.length() == 0){
            return "";
        }
        // Dynamic programming
        int n = s.length();
        // isPalindrome[i][j] means the substring from index i to j
        boolean[][] isPalindrome = new boolean[n][n];
        int longest = 1;
        int start = 0;
        
        for(int i = 0; i < n; i++){
            isPalindrome[i][i] = true;
        }
        
        for(int i = 0; i < n-1; i++){
            if(s.charAt(i) == s.charAt(i+1)){
                isPalindrome[i][i+1] = true;
                start = i;
                longest = 2;
            }
        }
        
        int tmp_length = 0;
        // palindrome = sub-palindrome + same left char and right char 
        for(int i = n-1; i >= 0; i--){
            for(int j = i+2; j < n; j++){
                // risk to use s.charAt(i-1) and s.charAt(j+1):
                // (i-1) or (j+1) would be out of bound
                if(isPalindrome[i+1][j-1] && s.charAt(i) == s.charAt(j)){
                    isPalindrome[i][j] = true;
                    tmp_length = j - i + 1;
                }
                
                if(tmp_length > longest){
                    start = i;
                    longest = tmp_length;
                }
            }
        }
        
        return s.substring(start, start+longest);
    }
}
