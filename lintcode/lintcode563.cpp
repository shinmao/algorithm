class Solution {
public:
    int backPackV(vector<int> &nums, int target) {
        int n = nums.size();
        
        // dp[i][j]: the ways of first i things filling up to size of j
        // if not put ith thing,
        // dp[i][j] = dp[i - 1][j]
        // if put the ith thing
        // dp[i][j] += dp[i - 1][j - nums[i - 1]]
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= target; j++) {
                if(j < nums[i - 1]){
                    dp[i][j] = dp[i - 1][j];
                }else {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        
        return dp[n][target];
    }
};
// 經過狀態壓縮
class Solution {
public:
    int backPackV(vector<int> &nums, int target) {
        int n = nums.size();

        vector<int> dp(target + 1, 0);
        
        dp[0] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = target; j >= 0; j--) {
                if(j >= nums[i - 1])
                    dp[j] += dp[j - nums[i - 1]];
            }
        }
        
        return dp[target];
    }
};