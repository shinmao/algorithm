/**
 * 注意！這題是要substring，也就是必須連續，並非subsequence
 * 回文串的長度可能為奇數也可能是偶數
 * 若為奇數，那中心點就只有一個char
 * 若為偶數，那中心點將有兩個char
 * 用下面這種function的寫法會簡潔很多
 * 然後把每一個字都當作中心點看看
 */
class Solution {
public:
    // center_l: index of left center
    // center_r: index of right center
    string palindrome(string s, int center_l, int center_r) {
        while(center_l >= 0 && center_r < s.size() && s[center_l] == s[center_r]) {
            center_l--;
            center_r++;
        }
        
        return s.substr(center_l + 1, center_r - center_l - 1);
    }
    
    string longestPalindrome(string s) {
        if(s.size() == 1) return s;
        string res;
        for(int i = 0; i < s.size(); i++) {
            string s1 = palindrome(s, i, i);
            string s2 = palindrome(s, i, i + 1);
            res = s1.size() > res.size() ? s1 : res;
            res = s2.size() > res.size() ? s2 : res;
        }
        
        return res;
    }
};