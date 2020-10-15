// 跟leetcode 862的思路幾乎一樣
// 只是題目要求區間長度在 [k1, k2]
// 這裏 deque 維護的是區間的起點
// for loop 列舉的是區間的終點
// 若終點為i，那麼我們的起點在 [i - k2, i - k1]
class Solution {
public:
    int maxSubarray5(vector<int> &nums, int k1, int k2) {
        int n = nums.size();
        if(n == 0 || n < k1)
            return 0;
        
        // prefix_sum[i]: the sum of first i elements
        vector<int> prefix_sum(n + 1, 0);
        for(int i = 1; i <= n; i++)
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        
        // dq stores start point
        deque<int> dq;
        int maxsum = INT_MIN;
        for(int i = 0; i <= n; i++) {
            // 若隊首小於(i - k2)，代表他已經在區間之外，彈出
            if(!dq.empty() && dq.front() + k2 < i)
                dq.pop_front();
            if(i - k1 >= 0) {   // i - k1是預防index out of bound
                while(!dq.empty() && prefix_sum[i - k1] < prefix_sum[dq.back()])  // 維護prefix sum的單調性
                    dq.pop_back();
                dq.push_back(i - k1);
            }
            if(!dq.empty())   // 更新largest sum
                maxsum = max(maxsum, prefix_sum[i] - prefix_sum[dq.front()]);
        }
        
        return maxsum;
    }
};