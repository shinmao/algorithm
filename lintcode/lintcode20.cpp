class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        // dp[i][j]: 投i次點數和為j的概率
        // dp[i][j] = dp[i - 1][j - k] * 1/6: 若當次得到的點數為k
        vector<pair<int, double>> res;
        vector<vector<double>> dp(n + 1, vector<double>(6*n + 1));
        
        // 丟一次dice，點數和1~6的機率都為1/6
        for(int i = 1; i < 7; ++i) {
            dp[1][i] = 1.0/6;
        }
        
        for(int i = 2; i < n + 1; ++i) {
            for(int j = 1; j < 6*i + 1; ++j) {
                for(int k = 1; k < 7; ++k) {
                    if(j < k)
                        continue;
                    dp[i][j] += dp[i-1][j-k] / 6.0;
                }
            }
        }
        
        for(int i = n; i < 6*n + 1; ++i)
            res.push_back(pair<int, double>(i, dp[n][i]));
        
        return res;
    }
};