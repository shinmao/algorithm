/**
 * 這種情況下dp[i]不能定義為nums[0..i]中的最大subarr和
 * 因為狀態轉移不好寫，我們不確定最大subarr在何處，無法確保連續
 * 我們可以把dp[i]定義為以nums[i]作結的最大subarr
 * 不過這樣最後return的答案就不能是dp[n - 1]，我們需要在遍歷一次整個dp數組
 * 狀態轉移方程：
 * 遍歷到nums[i]時，要嘛nums[i]自己成為一個subarray，要嘛nums[i]跟之前的subarray concate在一起
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> dp(n, nums[0]);
        for(int i = 1; i < n; i++) 
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        
        int res = INT_MIN;
        for(int i = 0; i < n; i++)
            res = max(res, dp[i]);
        
        return res;
    }
};