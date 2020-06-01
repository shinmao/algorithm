// version 1: only defeat 35.59%, so slow and high space complexity
class Solution {
    public int findShortestSubArray(int[] nums) {
        if(nums == null || nums.length == 0){
            return 0;
        }
        if(nums.length == 1){
            return 1;
        }
        
        Map<Integer, Integer> head = new HashMap<>();
        Map<Integer, Integer> tail = new HashMap<>();
        Map<Integer, Integer> deg = new HashMap<>();
        int most_deg = 1;
        int minsize = nums.length;
        
        head.put(nums[0], 0);
        tail.put(nums[0], 0);
        deg.put(nums[0], 1);
        
        for(int i = 1; i < nums.length; i++){
            if(head.containsKey(nums[i])){
                tail.replace(nums[i], i);
                deg.replace(nums[i], deg.get(nums[i]) + 1);
            }else{
                head.put(nums[i], i);
                tail.put(nums[i], i);
                deg.put(nums[i], 1);
            }
            
            if(deg.get(nums[i]) > most_deg){
                most_deg = deg.get(nums[i]);
            }
        }
        
        for( int k : deg.keySet() ){
            if(deg.get(k) == most_deg){
                minsize = Math.min( minsize, tail.get(k) - head.get(k) + 1 );
            }
        }
        
        return minsize;
    }
}

// version 2: don't need to use tail hashmap
// just one loop, each time update the length
// still only defeat 48.54%
class Solution {
    public int findShortestSubArray(int[] nums) {
        if(nums == null || nums.length == 0){
            return 0;
        }
        if(nums.length == 1){
            return 1;
        }
        
        // first<element, index>: first index of element
        Map<Integer, Integer> first = new HashMap<>();
        Map<Integer, Integer> deg = new HashMap<>();
        int most_deg = 1;
        int len = nums.length;
        
        first.put(nums[0], 0);
        deg.put(nums[0], 1);
        
        for(int i = 1; i < nums.length; i++){
            if(first.containsKey(nums[i])){
                deg.replace(nums[i], deg.get(nums[i]) + 1);
            }else{
                first.put(nums[i], i);
                deg.put(nums[i], 1);
            }
            
            if(deg.get(nums[i]) > most_deg){
                most_deg = deg.get(nums[i]);
                len = i - first.get(nums[i]) + 1;
            }else if(deg.get(nums[i]) == most_deg){
                len = Math.min(len, i - first.get(nums[i]) + 1);
            }
        }
        
        return len;
    }
}