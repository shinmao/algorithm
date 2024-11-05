class Solution {
public:
    // binary search
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        // [left, right] 搜索區間的兩端都會被涵蓋
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                // mid被檢查過，right要被涵蓋，所以是mid - 1
                right = mid -1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        // [left, right) 搜索區間右端不涵蓋
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                // 因為mid被蓋過了，right設為mid不會蓋過去
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};