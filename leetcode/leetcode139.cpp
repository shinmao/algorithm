/**
* 劃分型dp
* dp[i]: 前 i 個字是否可以用字典內的字組成
* e.g. | a | b |
* 如果前面 a 已經知道可行了
* 接下來我們只要看 b 可不可行
**/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            for(auto word : wordDict) {
                int len = word.length();
                if(i >= len && s.substr(i - len, len) == word) {
                    dp[i] = dp[i] || dp[i - len];
                }
            }
        }
        
        return dp[n];
    }
};