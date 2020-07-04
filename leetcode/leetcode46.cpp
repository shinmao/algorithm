// idea: use visited to judge that whether current number has been added to list
// we don't use start index here because each time of recursion we would iterate nums again
// beats over 16% of submission
class Solution {
    private:
        void dfs(vector<int>& nums, vector<bool>& visited, vector<int>& sub, vector<vector<int>>& res){
            if(sub.size() == nums.size()){
                res.push_back(sub);
                return;
            }
            
            for(int i = 0; i < nums.size(); ++i){
                if(visited.at(i)) continue;
                sub.push_back(nums.at(i));
                visited.at(i) = true;
                dfs(nums, visited, sub, res);
                sub.pop_back();
                visited.at(i) = false;
            }
        }
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<int> sub;
            vector<bool> visited(nums.size(), false);
            vector<vector<int>> res;
            
            dfs(nums, visited, sub, res);
            
            return res;
        }
    };
}

// idea: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
// beats over 86% of submission
class Solution {
private:
    void dfs(vector<int>& nums, int start, vector<vector<int>>& res){
        if(start == nums.size() - 1){
            res.push_back(nums);
            return;
        }
        
        for(int i = start; i < nums.size(); ++i){
            swap(nums.at(start), nums.at(i));
            dfs(nums, start+1, res);
            swap(nums.at(start), nums.at(i));
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        dfs(nums, 0, res);
        
        return res;
    }
};