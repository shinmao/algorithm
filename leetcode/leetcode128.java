// if we use Arrays.sort() first, it would take O(nlogn)
// set.remove() in while loop is very important
// although set.contains() takes only constant time
// but it still makes a significant difference in this problem if our hash bucket size is same for each time
// our set should only store the number we still not visit
// beats only over 49%
class Solution {
    public int longestConsecutive(int[] nums) {
        int longest = 0;
        if(nums == null || nums.length == 0) return longest;
        Set<Integer> set = new HashSet<>();
        
        for(int i : nums){
            set.add(i);
        }
        
        for(int i : nums){
            int next = i + 1;
            int prev = i - 1;
            while(set.contains(next)){
                set.remove(next);
                next += 1;
            }
            while(set.contains(prev)){
                set.remove(prev);
                prev -= 1;
            }
            longest = Math.max(longest, next-prev-1);
        }
        
        return longest;
    }
}