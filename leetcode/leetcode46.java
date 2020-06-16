// idea: use visited to judge that whether current number has been added to list
// we don't use start index here because each time of recursion we would iterate nums again
// beats over 91% of submission
class Solution {
    private void dfs(int[] nums, boolean[] visited, List<Integer> sublist, List<List<Integer>> result){
        if(sublist.size() == nums.length){
            result.add(new ArrayList<>(sublist));
            return;
        }
        
        for(int i = 0; i < nums.length; i++){
            if(visited[i]) continue;
            sublist.add(nums[i]);
            visited[i] = true;
            dfs(nums, visited, sublist, result);
            sublist.remove(sublist.size()-1);
            visited[i] = false;
        }
    }
    
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if(nums == null) return result;
        
        dfs(nums, new boolean[nums.length], new ArrayList<>(), result);
        
        return result;
    }
}