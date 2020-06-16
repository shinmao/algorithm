// idea: how to avoid duplicate
// why not use contains to remove duplicate?
// because we can avoid the operation in advance!
// {1, 2', 2"}
// 如果挑一個2，就挑2'
// 如果挑兩個2，就挑2
// 若不按順序挑，則會遇上重複的情況
// 在此題裡的if判斷就是 若當前的數字並非第一個 則continue掉
//            [1]
// start = 1 /^ \  start = 1
// i = 1    //   \  i = 2
//         v/     v
//     [1,2']     [1, 2"]
// beats over 99% of submission 
class Solution {
    private void dfs(int[] nums, int index, List<Integer> sublist, List<List<Integer>> result){
        result.add(new ArrayList<>(sublist));   
        
        for(int i = index; i < nums.length; i++){
            // 若是單純 nums[i] == nums[i-1] 作為條件則無法得到下一個2
            if(i > 0 && nums[i] == nums[i-1] && i > index) continue;
            sublist.add(nums[i]);
            dfs(nums, i+1, sublist, result);
            sublist.remove(sublist.size()-1);
        }
    }
    
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if(nums == null) return result;
        
        Arrays.sort(nums);    // 把相同的數字擠在一起才可以判斷是第一個還是第二個
        dfs(nums, 0, new ArrayList<>(), result);
        
        return result;
    }
}