// 最值得注意的一點:
// 傳參是list的地址
// 為何是 result.add(new ArrayList<>(sublist)) 而不是 result.add(sublist)
// 如果用後者，最後出來的結果會全部都是 [] 
// 因為我們傳入dfs的list是list的參數，全部指向第一個sublist
// 的確過程中，加入result的都是非空集合
// 但最後因為第一個sublist回到空集合的狀態，result的結果會理所當然都是空集合   result: [first sub, first sub, first sub...]
// 因此我們才有每到新的一層就new一個新的list，新的list在舊的list更動的時候就不會受到影響  result: [first sub, second sub, third sub...]
// 請參見readme中的#deepcopy

// idea: add or not add on each number
// the child nodes in the bottom line are our results
// beats over 100% of submission
class Solution {
    private void dfs(int[] nums, int start, List<Integer> sublist, List<List<Integer>> result){
        if(start == nums.length){
            // add into result only if we have arrive the last number
            result.add(new ArrayList<>(sublist));
            return;
        }
        
        // add current number
        sublist.add(nums[start]);
        dfs(nums, start+1, sublist, result);
        
        // not add current number
        sublist.remove(sublist.size()-1);
        dfs(nums, start+1, sublist, result);
    }
    
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if(nums == null) return result;
        
        dfs(nums, 0, new ArrayList<>(), result);
        
        return result;
    }
}

// idea: backtrack
// all nodes in the tree are our results
// [] -> [1] -> [1, 2] -> [1, 2, 3]
// backtack: [1, 2, 3] -> [1, 2] -> [1] -> [1, 3] -> [1] -> [] -> [2] ...
// beats over 100% of submission
class Solution {
    private void dfs(int[] nums, int start, List<Integer> sublist, List<List<Integer>> result){
        result.add(new ArrayList<Integer>(sublist));
        
        for(int i = start; i < nums.length; i++){
            sublist.add(nums[i]);
            dfs(nums, i+1, sublist, result);
            sublist.remove(sublist.size()-1);
        }
    }
    
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if(nums == null) return result;
        
        dfs(nums, 0, new ArrayList<>(), result);
        
        return result;
    }
}

// idea: still backtrack
// but a little different from the above in dfs
// beats only over 61% of submission
class Solution {
    private void dfs(int[] nums, int start, List<Integer> sublist, List<List<Integer>> result){
        result.add(sublist);
        
        for(int i = start; i < nums.length; i++){
            List<Integer> newlist = new ArrayList<>(sublist);
            newlist.add(nums[i]);
            dfs(nums, i+1, newlist, result);
        }
    }
    
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if(nums == null) return result;
        
        dfs(nums, 0, new ArrayList<>(), result);
        
        return result;
    }
}

// BFS
// because this problem does not request for permutation
// we prefer [1, 2, 3] to [1, 3, 2]
// beats over only 20% of submission
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new LinkedList<>();
        if(nums == null) return result;
        
        //Arrays.sort(nums);
        Queue<List<Integer>> queue = new LinkedList<>();
        queue.offer(new ArrayList<>());
        
        while(!queue.isEmpty()){
            List<Integer> subset = queue.poll();
            result.add(subset);
            
            for(int i = 0; i < nums.length; i++){
                if(subset.size() == 0 || nums[i] > subset.get(subset.size()-1)){
                    List<Integer> nextSet = new ArrayList<>(subset);
                    nextSet.add(nums[i]);
                    queue.offer(nextSet);
                }
            }
        }
        
        return result;
    }
}