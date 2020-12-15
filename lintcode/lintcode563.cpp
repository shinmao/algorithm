class Solution {
public:
    // dp[i]: the ways to fill the size i
    int backPackV(vector<int> &nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(auto n : nums) {
            for(int i = target; i >= n; --i) {
                // if I put the thing of size n into the backpack
                dp[i] += dp[i - n];
            }
        }
        
        return dp[target];
    }
};