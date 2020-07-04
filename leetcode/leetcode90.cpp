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
// beats over 82% of submission
class Solution {
    private:
        void dfs(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& res){
            res.push_back(sub);
            
            for(int i = start; i < nums.size(); ++i){
                // 若是單純 nums[i] == nums[i-1] 作為條件則無法得到下一個2
                if(i > 0 && nums.at(i) == nums.at(i-1) && i > start) continue;
                sub.push_back(nums.at(i));
                dfs(nums, i+1, sub, res);
                sub.pop_back();
            }
        }
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<int> sub;
            vector<vector<int>> res;
            // 把相同的數字擠在一起才可以判斷是第一個還是第二個
            sort(nums.begin(), nums.end());
            
            dfs(nums, 0, sub, res);
            
            return res;
        }
    };