// beats over 98% of submission
public class Solution {
    /*
     * @param A: an integer array
     * @param k: a postive integer <= length(A)
     * @param target: an integer
     * @return: A list of lists of integer
     */
    private void dfs(int[] nums, 
                        int k, 
                        int target, 
                        int sum, 
                        int start, 
                        List<Integer> sublist,
                        List<List<Integer>> result){
        if(sum == target && sublist.size() == k){
            result.add(new ArrayList<>(sublist));
            return;
        }
        
        for(int i = start; i < nums.length; i++){
            if(sum + nums[i] > target || sublist.size() + 1 > k) break;
            sublist.add(nums[i]);
            sum += nums[i];
            dfs(nums, k, target, sum, i+1, sublist, result);
            sum -= nums[i];
            sublist.remove(sublist.size()-1);
        }
    }
    
    public List<List<Integer>> kSumII(int[] A, int k, int target) {
        // write your code here
        List<List<Integer>> result = new LinkedList<>();
        if(A.length == 0 || k == 0 || target == 0) return result;  // check later
        
        Arrays.sort(A);
        dfs(A, k, target, 0, 0, new ArrayList<>(), result);
        
        return result;
    }
}