// each subsequence consists of consecutive and unique numbers
// idea: put number into subseq and mark the next number it needs
// we need to know how many subseq needs this number and how many number left can be used
// so we use these two hashmap
// iterating the nums:
// when someone needs this number, put it into the subseq
// when noone needs this number, open a new subseq
// at the same time, put all necessary numbers into it e.g. num+1, num+2
// if there are no necessary numbers, return false
class Solution {
    public boolean isPossible(int[] nums) {
        if(nums == null || nums.length < 3) return false;
        
        // freq<i, j>: j is the frequency of number i
        Map<Integer, Integer> freq = new HashMap<>();
        // eager<i, j>: j is the number of subseq who want i
        Map<Integer, Integer> eager = new HashMap<>();
        
        // put into freq
        for(int num : nums){
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }
        
        for(int num : nums){
            // check if number has been used out
            if(freq.get(num) <= 0){
                continue;
            }
            // someone needs this number
            // cannot use eager.containsKey
            // because when number of eager is 0, the key is still exist
            if(eager.getOrDefault(num, 0) > 0){
                eager.put(num, eager.get(num) - 1);
                eager.put(num + 1, eager.getOrDefault(num + 1, 0) + 1);
                freq.put(num, freq.get(num) - 1);
            }else if(freq.getOrDefault(num + 1, 0) > 0 && freq.getOrDefault(num + 2, 0) > 0){
                // if no one needs this number
                // open a new sequence
                eager.put(num + 3, eager.getOrDefault(num + 3, 0) + 1);
                freq.put(num, freq.get(num) - 1);
                freq.put(num + 1, freq.get(num + 1) - 1);
                freq.put(num + 2, freq.get(num + 2) - 1);
            }else{
                return false;
            }
        }
        
        return true;
    }
}