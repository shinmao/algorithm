// java 中最值得注意的一點:
// 傳參是list的地址
// 為何是 result.add(new ArrayList<>(sublist)) 而不是 result.add(sublist)
// 如果用後者，最後出來的結果會全部都是 [] 
// 因為我們傳入dfs的list是list的參數，全部指向第一個sublist
// 的確過程中，加入result的都是非空集合
// 但最後因為第一個sublist回到空集合的狀態，result的結果會理所當然都是空集合   result: [first sub, first sub, first sub...]
// 因此我們才有每到新的一層就new一個新的list，新的list在舊的list更動的時候就不會受到影響  result: [first sub, second sub, third sub...]
// 請參見readme中的#deepcopy
// C++ 的push_back則是deepcopy的效果

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

/**
 * 思路：backtrack
 * beats over 100%
 */
class Solution {
public:
    void dfs(vector<int> nums,
            int start,
            vector<int> s, 
            vector<vector<int>>& res) {
        res.push_back(s);
        
        for(int i = start; i < nums.size(); i++) {
            s.push_back(nums[i]);
            dfs(nums, i + 1, s, res);
            s.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return {{}};
        
        vector<int> s;
        vector<vector<int>> res;
        dfs(nums, 0, s, res);
        
        return res;
    }
};

// BFS
// idea: 從上到下每一層各是一個元素的，兩個的，三個的...
// 每一次都遍歷整個數組並且push進去
// 但是這是個subset問題，所以不能有重複元素的數組
// 在 [1,2,3] 和 [1,3,2] 中我們會選擇 前者
// 所以避免重複的寫法就是 維持升序！
// beats over only 12% of submission
class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> res;
            sort(nums.begin(), nums.end());
            
            queue<vector<int>> q;
            q.push(vector<int>());
            
            while(!q.empty()){
                vector<int> sub(q.front().begin(), q.front().end());
                q.pop();
                res.push_back(sub);
                
                for(auto e : nums){
                    if(sub.size() == 0 || e > sub.back()){
                        vector<int> next(sub.begin(), sub.end());
                        next.push_back(e);
                        q.push(next);
                    }
                }
            }
            
            return res;
        }
    };