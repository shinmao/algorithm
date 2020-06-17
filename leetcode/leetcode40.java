class Solution {
    private void dfs(int[] cand, 
                     int sum, 
                     int target, 
                     int start, 
                     List<Integer> sublist, 
                     List<List<Integer>> result){
        if(sum == target){
            result.add(new ArrayList<>(sublist));
            return;
        }

        for(int i = start; i < cand.length; i++){
            if(sum + cand[i] > target) break;
            // make sure no duplications in the result set 
            if(i > 0 && cand[i] == cand[i-1] && i > start) continue;
            sublist.add(cand[i]);
            sum += cand[i];
            // i+1 makes sure only use once in one combination
            dfs(cand, sum, target, i+1, sublist, result);
            sublist.remove(sublist.size()-1);
            sum -= cand[i];
        }
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new LinkedList<>();
        if(candidates.length == 0 || target == 0) return result;
        
        Arrays.sort(candidates);
        dfs(candidates, 0, target, 0, new ArrayList<>(), result);
        
        return result;
    }
}