class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        if(n == 1)
            return 1;
        
        unordered_map<char, int> cnt;
        int len1 = 0, len2 = 0;
        
        for(auto chr : s) {
            if(cnt.count(chr) != 0) {
                cnt[chr]++;
            }else{
                cnt[chr] = 1;
            }
        }
        
        // use double center
        for(auto it = cnt.begin(); it != cnt.end(); it++) {
            if(it->second % 2 == 0)
                len1 += it->second;
        }
            
        // use single center
        bool center = false;
        for(auto it = cnt.begin(); it != cnt.end(); it++) {
            if(it->second % 2 != 0) {
                if(center == false) {
                    center = true;
                    len2 += 1;
                    len2 += it->second - 1;
                }else {
                    len2 += it->second - 1;
                }
            }else {
                len2 += it->second;
            }
        }
        
        return max(len1, len2);
    }
};