public class Solution {
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    public List<List<Integer>> permuteUnique(int[] nums) {
        // write your code here
        List<List<Integer>> result = new ArrayList<>();
        if(nums == null){
            return result;
        }
        
        Arrays.sort(nums);
        traverse(nums, new boolean[nums.length], new ArrayList<>(), result);
        return result;
    }
    
    private void traverse(int[] nums, boolean[] visited, List<Integer> permutation, List<List<Integer>> result) {
        if(permutation.size() == nums.length){
            result.add(new ArrayList<>(permutation));
            return;
        }
        
        for(int i = 0; i < nums.length; i++){
            if(visited[i] == true){
                continue;
            }
            // 同樣的元素一定要照index排列
            if(i > 0 && nums[i] == nums[i -1] && visited[i-1] == false){
                continue;
            }
            
            permutation.add(nums[i]);
            visited[i] = true;
            traverse(nums, visited, permutation, result);
            permutation.remove(permutation.size() - 1);
            visited[i] = false;
        }
    }
};