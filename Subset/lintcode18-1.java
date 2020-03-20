import java.util.*;

public class Solution {
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        // write your code here
        List<List<Integer>> result = new ArrayList<>();
        if(nums == null){
            return result;
        }
        
        Arrays.sort(nums);
        traverse(nums, 0, new ArrayList<>(), result);
        return result;
    }
    
    private void traverse(int[] nums, int index, List<Integer> subset, List<List<Integer>> result) {
        result.add(new ArrayList<>(subset));
        
        for(int i = index; i < nums.length; i++){
            // 注意這邊要先寫 i > 0 的條件判斷，不然還是會AOFBE
            if(i > 0 && nums[i] == nums[i - 1] && i > index){
                continue;
                // 若是有[1,2']和[1,2'']的子集，則選[1,2']，也就是i == index的情況
            }
            subset.add(nums[i]);
            traverse(nums, i+1, subset, result);
            subset.remove(subset.size() - 1);
        }
    }
}