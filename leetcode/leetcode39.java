// beats over 99% of submission
class Solution {
    private void dfs(int[] cans, 
                     int start, 
                     int sum, 
                     int target, 
                     List<Integer> sublist, 
                     List<List<Integer>> result){
        if(sum == target){
            result.add(new ArrayList<>(sublist));
            return;
        }
        
        for(int i = start; i < cans.length; i++){
            // if I already find that [2,2,2,2] would bigger than target which is 7
            // I don't need to backtrack and search [2,2,2,3] again because it should be bigger than 7 too
            // and I also sort the array first, so I can break here
            if(sum + cans[i] > target) break;
            sublist.add(cans[i]);
            sum += cans[i];
            // the element in sublist can be duplicate so the start index would be the same
            // but if i start from 2, here should also start from 2 because it would cause to duplicate sublist in result
            dfs(cans, i, sum, target, sublist, result);
            sum -= cans[i];
            sublist.remove(sublist.size()-1);
        }
    }
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new LinkedList<>();
        if(candidates == null || candidates.length == 0 || target == 0) return result;
        
        Arrays.sort(candidates);
        dfs(candidates, 0, 0, target, new ArrayList<>(), result);
        
        return result;
    }
}