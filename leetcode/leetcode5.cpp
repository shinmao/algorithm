// idea: DP
// beats only over 7% of submission
class Solution {
public:
    string longestPalindrome(string s) {
        int max = 1;
        int start = 0;
        int len = s.size();
        if(len == 0) return "";
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        // init dp to be false
        for(int i = 0; i < len; ++i) {
            dp[i][i] = true;
        }
        for(int i = 0; i < len - 1; ++i) {
            dp[i][i + 1] = (s[i] == s[i + 1]);
            if(dp[i][i + 1]) 
                max = 2, start = i;
        }
        for(int l = 2; l < len; ++l) {
            // len starts from 3
            for(int i = 0; i < len - l; ++i) {
                int j = i + l;
                dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]) == true;
                if(dp[i][j] && (j - i + 1) > max)
                    max = j - i + 1, start = i;
            }
        }
        return s.substr(start, max);
    }
};