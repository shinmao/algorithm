/**
 * 這題花多了點時間才做出來
 * 思路大體跟house robber一樣
 * 只不過要解決一圈的問題
 * 那一圈跟原本一排到底差在哪裡呢？
 * 一圈的話那搶第一個就不能再搶最後一個了
 * 所以有只有幾種可能性：搶第一個，搶最後一個，或者兩個都不搶
 * 而我們只要比較搶第一個和搶最後一個中的最大值就好，反正兩個都不搶一定最沒錢
 * 就是把原本的題目套上兩個區間[0...n - 2]和[1...n - 1]
 * 剩下就都一樣了
 */
class Solution {
public:
    int robhelper(vector<int>& nums, int start) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        
        // base case for i == 0
        dp[0] = 0;
        // base case for i == 1
        dp[1] = nums[start];
        
        for(int i = 2; i <= n - 1; i++) {
            dp[i] = max(nums[start + i - 1] + dp[i - 2], dp[i - 1]);
        }
        
        return dp[n - 1];
    }
    
    int rob(vector<int>& nums) {
       int n = nums.size();
        if(n == 0)
            return 0;
        else if(n == 1)
            return nums[0];
        
        return max(robhelper(nums, 0), robhelper(nums, 1));
    }
};