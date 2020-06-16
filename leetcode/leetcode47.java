// beats over 99% of submission
class Solution {
    private void dfs(int[] nums, boolean[] visited, List<Integer> sublist, List<List<Integer>> result){
        if(sublist.size() == nums.length){
            result.add(new ArrayList<>(sublist));
            return;
        }
        
        for(int i = 0; i < nums.length; i++){
            if(visited[i]) continue;
            // if current number is same as prev but not visited
            if(i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            sublist.add(nums[i]);
            visited[i] = true;
            dfs(nums, visited, sublist, result);
            sublist.remove(sublist.size()-1);
            visited[i] = false;
        }
    }
    
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if(nums == null) return result;
        
        Arrays.sort(nums);
        dfs(nums, new boolean[nums.length], new ArrayList<>(), result);
        
        return result;
    }
}