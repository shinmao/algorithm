// 定義還蠻好想的：dp[i][j] s的前i個能不能匹配上p的前j個
// 在寫這題還要注意OFB！！
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        
        dp[0][0] = true;
        // 若s為長度0，p只有可能給個*
        for(int j = 1; j <= p.size(); j++) {
            // j > 1 只是為了避免後面[j - 2] index out of range
            dp[0][j] = j > 1 && p[j - 1] == '*' && dp[0][j - 2];
        }
        
        for(int i = 1; i <= s.size(); i++) {
            for(int j = 1; j <= p.size(); j++) {
                if(p[j - 1] != '*') {
                    // 沒有長度的顧慮
                    // 前面都一樣 && 後面字一樣 or pattern == '.'
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }else {
                    // 最重要的地方
                    // 如果a*代表0個字，直接把a*拔掉，i繼續往下匹配 -> dp[i][j - 2]
                    // 如果a*代表>=1個字，要嘛匹配a，要嘛.*匹配任意字
                    dp[i][j] = j > 1 && dp[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};