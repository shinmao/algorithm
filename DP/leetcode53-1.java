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