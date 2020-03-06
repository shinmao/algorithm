import java.util.HashMap;

public class Solution {
    /**
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    public static int longestPalindrome(String s) {
        // write your code here
        int longest = 0;
        // the map to store the occurences of each character in string
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        // find center of oddPalindrome
        boolean find_center = false;
        for(int i = 0; i < s.length(); i++){
            if(!map.containsKey(s.charAt(i))){
                map.put(s.charAt(i), 1);
            }else{
                int replaced = map.get(s.charAt(i));
                replaced += 1;
                map.replace(s.charAt(i), replaced);
            }
        }
        for(Character key: map.keySet()){
            int count = map.get(key);
            if(count == 1 && find_center == false){
                // should be center
                longest += 1;
                find_center = true;
            }
            if(count % 2 == 1 && count > 1){
                if(find_center == false){
                    longest += 1;
                    find_center = true;
                }
                count -= 1;
                map.replace(key, count);
            }
            if(count % 2 == 0 && count > 0){
                // evenPalindrome
                longest += count;
            }
        }
        return longest;
    }
}
