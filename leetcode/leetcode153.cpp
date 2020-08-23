// beats over 61% of submission
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int start = 0, end = nums.size() - 1, mid;
        while(start < end) {
            mid = start + ((end - start) >> 1);
            if(nums[mid] > nums[end]) start = mid + 1;
            else end = mid;
        }
        return nums[start];
    }
};

// beats over 94% of submission
int findMin(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    int start = 0, end = nums.size() - 1, mid;
    while(start < end) {
        if(nums[start] < nums[end]) break;
        mid = start + ((end - start) >> 1);
        if(nums[mid] > nums[end]) start = mid + 1;
        else end = mid;
    }
    return nums[start];
}