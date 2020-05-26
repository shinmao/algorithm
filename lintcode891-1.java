public class Solution {
    /**
     * @param s: a string
     * @return boolean: whether you can make s a palindrome by deleting at most one character
     */
    public boolean validPalindrome(String s) {
        // Write your code here
        int n = s.length();
        boolean[][] isPalindrome = new boolean[n][n];
        
        for(int i = 0; i < n; i++){
            isPalindrome[i][i] = true;
        }
        
        for(int i = 0; i < n-1; i++){
            if(s.charAt(i) == s.charAt(i+1)){
                isPalindrome[i][i+1] = true;
            }
        }
        
        for(int i = n-1; i >= 0; i--){
            for(int j = i+2; j < n; j++){
                isPalindrome[i][j] = s.charAt(i) == s.charAt(j) && isPalindrome[i+1][j-1];
            }
        }
        
        if(isPalindrome[0][n-1]){
            return true;
        }

        for(int left = 0, right = n-1; left < right; left++, right--){
            if(s.charAt(left) != s.charAt(right)){
               return isPalindrome[left+1][right] || isPalindrome[left][right-1];
            }
        }
        
        return false;
    }
}