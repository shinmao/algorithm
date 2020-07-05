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
}

// idea: also use swap idea
// however, pay attention that we can not pass by reference for nums here
// because we need sorted array to skip duplicate here
// but swap will destruct our sorted order
// therefore, pass by value is the best way here
// beats over 83% of submission
class Solution {
private:
    void dfs(vector<int> nums, int start, vector<vector<int>>& res){
        if(start == nums.size() - 1){
            res.push_back(nums);
            return;
        }
        
        for(int i = start; i < nums.size(); ++i){
            if(i != start && nums[i] == nums[start]) continue;
            swap(nums[start], nums[i]);
            dfs(nums, start+1, res);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, res);
        return res;
    }
};

// a hack solution
// beats over 57% of submission
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        while(next_permutation(nums.begin(), nums.end())){
            res.push_back(nums);
        }
        
        return res;
    }
};