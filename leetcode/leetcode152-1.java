class Solution {
    public int maxProduct(int[] nums) {
        if(nums == null || nums.length == 0){
            return 0;
        }
        if(nums.length == 1){
            return nums[0];
        }
        
        // maxp[i]: maximum product of subarray ends at index i
        int[] maxp = new int[nums.length];
        // minp[i]: minimum product of subarray ends at inedx i
        int[] minp = new int[nums.length];
        
        maxp[0] = nums[0];
        minp[0] = nums[0];
        
        int max = nums[0];
        
        for(int i = 1; i < nums.length; i++){
            if(nums[i] > 0){
                maxp[i] = Math.max(nums[i], nums[i] * maxp[i-1]);
                minp[i] = Math.min(nums[i], nums[i] * minp[i-1]);
            }else if(nums[i] < 0){
                maxp[i] = Math.max(nums[i], nums[i] * minp[i-1]);
                minp[i] = Math.min(nums[i], nums[i] * maxp[i-1]);
            }
            
            if(maxp[i] > max){
                max = maxp[i];
            }
        }
        
        return max;
    }
}