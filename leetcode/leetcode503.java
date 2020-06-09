class Solution {
    public int[] nextGreaterElements(int[] nums) {
        if(nums == null || nums.length == 0) return new int[0];
        
        int[] result = new int[nums.length];
        Arrays.fill(result, -1);
        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < 2*nums.length; i++){
            int idx = i % nums.length;
            while(!stack.isEmpty() && nums[stack.peek()] < nums[idx]){
                result[stack.pop()] = nums[idx];
            }
            stack.push(idx);
        }
        
        return result;
    }
}