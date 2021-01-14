/** dp[i][j]: 代表i到j之間的最長回文串的長度
 * 為什麼要這樣定義呢？
 * 因為如果s[i] == s[j]
 * 那麼他必定是dp[i+1][j-1]之間的最長子序列+2
 * 如果不等於
 * 那就是看dp[i+1][j]和dp[i][j-1]哪個比較長囉
 * 這便是我們的狀態轉移
 * 有趣的是這題的遍歷順序，直接看代碼可能會無法理解
 * 畫個圖，看看更新狀態所需要的狀態，就能理解為何是這樣的遍歷順序！
 */
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n == 1) return 1;
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        
        return dp[0][n - 1];
    }
};