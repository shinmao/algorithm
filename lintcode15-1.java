import java.util.*;

public class Solution {
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    public List<List<Integer>> permute(int[] nums) {
        // write your code here
        List<List<Integer>> result = new ArrayList<>();
        if(nums == null){
            return result;
        }
        
        Arrays.sort(nums);
        traverse(nums, new boolean[nums.length], new ArrayList<>(), result);
        return result;
    }
    // use boonums array to record that the node has been visited or not
    private void traverse(int[] nums, boolean[] boonums, List<Integer> subset, List<List<Integer>> result) {
        if(subset.size() == nums.length){
            result.add(new ArrayList<>(subset));
            return;
        }
        
        for(int i = 0; i < nums.length; i++){
            if(boonums[i] != true){
                subset.add(nums[i]);
                boonums[i] = true;
                traverse(nums, boonums, subset, result);
                subset.remove(subset.size() - 1);
                boonums[i] = false;
            }
        }
    }
}