// beats over 44% of submission
class Solution {
    private:
        void dfs(vector<int>& nums, vector<bool>& visited, vector<int>& sub, vector<vector<int>>& res){
            if(sub.size() == nums.size()){
                res.push_back(sub);
                return;
            }
            
            for(int i = 0; i < nums.size(); i++){
                if(visited.at(i)) continue;
                if(i > 0 && nums.at(i) == nums.at(i-1) && !visited.at(i-1)) continue;
                sub.push_back(nums.at(i));
                visited.at(i) = true;
                dfs(nums, visited, sub, res);
                sub.pop_back();
                visited.at(i) = false;
            }
        }
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<int> sub;
            vector<vector<int>> res;
            vector<bool> visited(nums.size(), false);
            sort(nums.begin(), nums.end());
            
            dfs(nums, visited, sub, res);
            
            return res;
        }
    };