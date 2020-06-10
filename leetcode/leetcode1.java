class Solution {
    public int[] twoSum(int[] nums, int target) {
        if(nums == null || nums.length == 0) return new int[0];
        
        // map< target - current num, current index>
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            if(map.containsKey(nums[i])){
                return new int[]{ map.get(nums[i]), i };
            }
            map.put(target - nums[i], i);
        }
        
        return new int[0];
    }
}

// another idea: two pointers
// sort and use class to associate index with value
class Solution {
    private class Num {
        private int index;
        private int value;
        Num(int index, int value) {
            this.index = index;
            this.value = value;
        }
        
        public int getIdx(){
            return this.index;
        }
        
        public int getVal(){
            return this.value;
        }
    }
    
    public int[] twoSum(int[] nums, int target) {
        if(nums == null || nums.length == 0) return new int[0];
        
        List<Num> list = new ArrayList<>();
        for(int i = 0; i < nums.length; i++){
            list.add(new Num(i, nums[i]));
        }
        Collections.sort(list, (num1, num2) -> num1.getVal() - num2.getVal());
        
        int head = 0;
        int tail = list.size() - 1;
        while(list.get(head).getVal() + list.get(tail).getVal() != target){
            int sum = list.get(head).getVal() + list.get(tail).getVal();
            if(sum > target) tail--;
            if(sum < target) head++;
            if(head >= tail) return new int[0];
        }
        
        int[] result = new int[2];
        result[0] = Math.min(list.get(head).getIdx(), list.get(tail).getIdx());
        result[1] = Math.max(list.get(head).getIdx(), list.get(tail).getIdx());
        return result;
    }
}