class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums.length == 0 || nums == null){
            return 0;
        }
        
        if(nums.length == 1){
            return 1;
        }
        
        // maximum length ends at index i
        int[] mxlen = new int[nums.length];
        int max = 0;
        Arrays.fill(mxlen, 1);
        
        for(int i = 1; i < nums.length; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    mxlen[i] = Math.max(mxlen[j] + 1, mxlen[i]);
                }
            }
            if(mxlen[i] > max){
                max = mxlen[i];
            }
        }
        
        return max;
    }
}