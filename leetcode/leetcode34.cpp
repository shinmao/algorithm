class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.size() == 0) return vector<int>({-1, -1}); 
        if(target < *(nums.begin()) || target > *(--nums.end())) return vector<int>({-1, -1});
        int start = 0, end = nums.size() - 1, mid;
        while(start + 1 < end) {
            mid = start + ((end - start) >> 1);
            if(nums[mid] == target) end = mid;
            else if(nums[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        if(nums[start] == target) res.push_back(start);
        else if(nums[end] == target) res.push_back(end);
        if(res.size() < 1) return vector<int>({-1, -1});
        end = nums.size() - 1;
        while(start + 1 < end) {
            mid = start + ((end - start) >> 1);
            if(nums[mid] == target) start = mid;
            else if(nums[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        if(nums[end] == target) res.push_back(end);
        else if(nums[start] == target) res.push_back(start);
        return res;
    }
};