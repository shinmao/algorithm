class Solution {
public:
    // 雙指針的時間複雜度是O(2n)
    // 因為左右指針不會重疊
    // 最多就只是兩個指針都把arr visit了一次
    int minSubArrayLen(int target, vector<int>& nums) {
        // sliding window with two pointers
        int lf_ptr = 0;
        int arrlen = 0;
        int sum = 0;
        int window_size = INT32_MAX;
        // 主要是右指針先動，左指針不動，漸漸擴大arr size直到sum > target
        // 若大於target 則動左指針來減少arr size 來看最小arr size可以達到目標
        for (int rh_ptr = 0; rh_ptr < nums.size(); rh_ptr++) {
            sum += nums[rh_ptr];
            while (sum >= target) {
                int curr_window_size = rh_ptr - lf_ptr + 1;
                if (curr_window_size < window_size) {
                    window_size = curr_window_size;
                }
                sum -= nums[lf_ptr];
                lf_ptr++;
            }
        }

        // 最後如果window_size都沒有變小就代表是0
        return window_size == INT32_MAX ? 0 : window_size;
    }
};