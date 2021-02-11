class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        else if(n == 1)
            return nums[0];
        
        // dp[i]: 搶前i個house所可以得到的最大利益
        // 若搶了ith個
        // dp[i] = nums[i - 1] + dp[i - 2]
        // 若不搶ith個
        // dp[i] = dp[i - 1]
        vector<int> dp(n + 1, 0);
        
        // base case for i == 0
        dp[0] = 0;
        // base case for i == 1
        dp[1] = nums[0];
        
        for(int i = 2; i <= n; i++)
            dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1]);
        
        return dp[n];
    }
};
/**
 * 發現狀態轉移都只依賴鄰近的狀態
 * 二話不說 - 狀壓
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        else if(n == 1)
            return nums[0];
        
        int dp_i = 0;
        int dp_i_1 = nums[0];
        int dp_i_2 = 0;
        
        for(int i = 2; i <= n; i++){
            dp_i = max(nums[i - 1] + dp_i_2, dp_i_1);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        
        return dp_i;
    }
};