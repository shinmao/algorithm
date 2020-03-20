import java.util.*;

public class Solution {
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    public List<List<Integer>> subsets(int[] nums) {
        // write your code here
        List<List<Integer>> result = new ArrayList<>();
        if(nums == null){
            return result;
        }
        Arrays.sort(nums);
        traverse(nums, 0, new ArrayList<Integer>(), result);
        return result;
    }
    // traverse 會先把某個node下的subnode遍歷過，最後再經由remove回到最初的狀態
    private void traverse(int[] nums, int index, List<Integer> subset, List<List<Integer>> result){
        result.add(new ArrayList<Integer>(subset));
        
        for(int i = index; i < nums.length; i++){
            subset.add(nums[i]);
            // traverse the subset of nums[i]
            traverse(nums, i + 1, subset, result);
            // backtrack
            subset.remove(subset.size() - 1);
        }
    }
}