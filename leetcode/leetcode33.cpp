// beats over 69.9% of submission
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1) {
            if(target == nums[0]) return 0;
            else return -1;
        }
        // find rotate pivot
        int rotate = -1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] < nums[i - 1]) rotate = i;
        }
        int start = 0, end = nums.size() - 1, mid = 0;
        if(rotate != -1) {
            // if rotated, divide by rotate pivot
            if(nums[rotate] == target) return rotate;
            if(target > nums[rotate - 1] || target < nums[rotate]) return -1;
            if(target <= *(--nums.end())) start = rotate;
            else if(target >= *(nums.begin())) end = rotate - 1;
        }
        // BS
        while(start <= end) {
            mid = start + ((end - start) >> 1);
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }
};

// beats over 96.5% of submission
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1) {
            if(target == nums[0]) return 0;
            else return -1;
        }
        int start = 0, end = nums.size() - 1, mid = 0;
        while(start <= end) {
            mid = start + ((end - start) >> 1);
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[start]) {
                // left is in order
                if(target < nums[mid] && target >= nums[start]) {
                    // target is in left section
                    end = mid - 1;
                }else {
                    start = mid + 1;   
                }
            }else {
                // right is in order
                if(target > nums[mid] && target <= nums[end]) {
                    // target is in right section
                    start = mid + 1;
                }else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};