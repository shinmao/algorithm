// beats over 67% of submission
class Solution {
    public int maxSubArray(int[] nums) {
        if(nums.length == 0 || nums == null){
            return 0;
        }
        if(nums.length == 1){
            return nums[0];
        }
        
        // sum[i]: maximum sum of subarray ends at index i
        int[] sum = new int[nums.length];
        sum[0] = nums[0];
        int max = sum[0];
        
        for(int i = 1; i < nums.length; i++){
            sum[i] = Math.max(sum[i-1] + nums[i], nums[i]);
            if(sum[i] > max){
                max = sum[i];
            }
        }
        
        return max;
    }
}

// another idea
// how to get the max sum of subarray which ends at specific number
// e.g. 2, -3, 4, -1 for ending at -1, which head would we choose to start for subarray
// we already know prefix sum ends at -1 is 2
// subarray ends at 2 is 2, which means [-3, 4, -1] sum is 2 - 2 = 0
// subarray ends at -3 is -1, which means [4, -1] sum is 2 - (-1) = 3
// subarray ends at 4 is 3, which means [-1] sum is 2 - 3 = -1
// so the max sum of subarray ending at -1 is 3
// only beats over 67% of submission
class Solution {
    public int maxSubArray(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        if(nums.length == 1) return nums[0];
        
        int[] prefixSum = new int[nums.length+1];
        prefixSum[0] = 0;
        int max = Integer.MIN_VALUE;
        int min = 0;
        
        for(int i = 1; i <= nums.length; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
            max = Integer.max(max, prefixSum[i] - min);
            min = Integer.min(min, prefixSum[i]);
        }
        
        return max;
    }
}