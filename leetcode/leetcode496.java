class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] result = new int[nums1.length];
        if(nums1 == null || nums2 == null || nums1.length == 0 || nums2.length == 0 || nums1.length > nums2.length){
            for(int i : result){
                i = -1;
            }
            return result;
        }
        
        // map<value, next greater element>
        Map<Integer, Integer> map = new HashMap<>();
        for(int i : nums2){
            map.put(i, -1);
        }
        // monotonic descending stack
        Stack<Integer> stack = new Stack<>();
        
        for(int i = 0; i < nums2.length; i++){
            while(!stack.isEmpty() && nums2[i] > stack.peek()){
                map.put(stack.pop(), nums2[i]);
            }
            stack.push(nums2[i]);
        }
        
        for(int i = 0; i < nums1.length; i++){
            result[i] = map.get(nums1[i]);
        }
        
        return result;
    }
}