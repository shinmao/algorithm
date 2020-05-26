public class Solution {
    /**
     * @param s: a string
     * @return boolean: whether you can make s a palindrome by deleting at most one character
     */
    public boolean validPalindrome(String s) {
        // Write your code here
        int left = 0, right = s.length() - 1;
        
        while(left < right){
            if(s.charAt(left) != s.charAt(right)){
                break;
            }
            left++;
            right--;
        }
        
        if(left >= right){
            return true;
        }
        
        return isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1);
    }
    
    private boolean isPalindrome(String s, int left, int right){
        while(left < right){
            if(s.charAt(left) != s.charAt(right)){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}