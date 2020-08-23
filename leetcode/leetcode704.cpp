class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(target < -9999 || target > 9999) return -1;
        int start = 0, end = nums.size() - 1, mid = 0;
        while(start <= end) {
            mid = start + ((end - start) >> 1);
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) 
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
};