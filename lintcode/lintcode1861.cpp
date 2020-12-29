class Solution {
public:
    /**
     * @param arr: the steps whether have glue
     * @return: the sum of the answers
     */
    int ratJump(vector<int> &arr) {
        if(arr.size() == 0)
            return 0;
        
        int n = arr.size();
        const long long MOD = 1000000007;
        vector<int> even = {1, 3, 4};
        vector<int> odd = {1, 2, 4};
            
        /**
         * condition: 第i層台階，奇/偶次jmp
         * dp[i][j]: 第j次跳到第i層的方案數
         * 奇數次跳到i，接下來是偶數次
         * dp[i + even][0] += dp[i][1];
         * 偶數次跳到i，接下來是奇數次
         * dp[i + odd][1] += dp[i][0];
         */
        vector<vector<long long>> dp(n + 5, vector<long long>(2, 0));
        
        dp[0][0] = 1;
        for(int i = 0; i < n - 1; i++) {
            for(int k = 0; k < 3; k++) {
                if(i + even[k] >= n || arr[i + even[k]] == 0) {
                    dp[i + even[k]][0] += dp[i][1];
                    dp[i + even[k]][0] %= MOD;
                }
                if(i + odd[k] >= n || arr[i + odd[k]] == 0) {
                    dp[i + odd[k]][1] += dp[i][0];
                    dp[i + odd[k]][1] %= MOD;
                }
            }
        }
        
        long long ans = 0;
        for(int i = n - 1; i < n + 4; i++) {
            ans = (ans + dp[i][0] + dp[i][1]) % MOD;
        }
        
        return (int)ans;
    }
};