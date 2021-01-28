/**
 * 是說刪除後的目標不就是兩個字串的LCS嘛
 * 所以一樣是算兩個字串的LCS長度
 * 下面寫法直接用了狀態壓縮
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int pre_val = 0, cur_val = 0;
        
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= m; i++) {
            pre_val = 0;
            for(int j = 1; j <= n; j++) {
                cur_val = dp[j];
                if(word1[i - 1] == word2[j - 1])
                    dp[j] = pre_val + 1;
                else
                    dp[j] = max(dp[j - 1], dp[j]);
                pre_val = cur_val;
            }
        }
        
        return m - dp[n] + n - dp[n];
    }
};