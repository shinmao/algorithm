import java.util.*;

public class Solution {
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    public List<List<Integer>> subsets(int[] nums) {
        // write your code here
        List<List<Integer>> result = new ArrayList<>();
        if(nums == null){      // 這邊不進行nums.length的例外判斷因為[]也有subset
            return result;
        }
        Arrays.sort(nums);     // 因為裡面的list必須要大小排列，所以外面要先sort過
        traverse(nums, 0, new ArrayList<>(),result);
        return result;
    }
    // tree的思路，每一層都是探討num要或不要，然後下去traverse
    private void traverse(int[] nums, int index, List<Integer> subset, List<List<Integer>> result){
        // DFS with recursion
        if(index == nums.length){     // tree的層數就跟nums的數量一樣
            result.add(new ArrayList<Integer>(subset));    // leaf node即是所有的subset
            return;
        }
        
        subset.add(nums[index]);     // 要這個number
        traverse(nums, index + 1, subset, result);
        
        subset.remove(subset.size() - 1);   // 不要這個number
        traverse(nums, index + 1, subset, result);
    }
}