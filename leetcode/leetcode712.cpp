/**
 * 思路：一樣可以轉換成LCS問題，只是這題要求的是擁有最大ASCII總和的LCS
 * 比較特殊的地方是發現兩個字相等的地方
 * 兩個字相等的時候也未必要把他放入LCS
 * 因為要求的是ASCII總和最大的LCS，所以可放可不放
 */
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        int ascii_sum = 0;
        for(auto c : s1)
            ascii_sum += (int)c;
        for(auto c : s2)
            ascii_sum += (int)c;
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = max(dp[i - 1][j - 1] + (int)s1[i - 1], max(dp[i][j - 1], dp[i - 1][j]));
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        
        return ascii_sum - 2 * dp[m][n];
    }
};