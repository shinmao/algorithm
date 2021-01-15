/**
 * dp[i]: 以nums[i]為結尾的最長子序列長度
 * 最後dp裡面存的是以各個index為結尾的最長長度
 * 所以最後還要整個dp數組跑一遍看最長是多少
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        
        int res = INT_MIN;
        for(int i = 0; i < n; i++) {
            res = max(res, dp[i]);
        }
        
        return res;
    }
};
/**
 * 有一個紙牌遊戲叫patience game 可以解決最長上升子序列的問題
 * 每一次把點數小的牌放到點數比他大的牌堆上
 * 若有多個可以選擇的牌堆，那就放最左邊那個
 * 若沒有可以選擇的牌堆，那就開一個新的牌堆
 * 最後牌堆數就是最長上升子序列的最大長度！
 * ****如何找到比自己點數大的牌堆呢？****
 * 用尋找左側邊界的binary search
 * 若發現左側邊界超出bound
 * 那就代表沒有牌堆比他大，那我們就可以新增牌堆數
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> top(n, 0);
        int piles = 0;
        for(int i = 0; i < n; i++) {
            int card = nums[i];
            int l = 0, r = piles;
            while(l < r) {
                int mid = l + (r - l)/2;
                if(top[mid] > card)
                    r = mid;
                else if(top[mid] < card)
                    l = mid + 1;
                else
                    r = mid;
            }
            if(l == piles)
                piles++;
            top[l] = card;
        }
        
        return piles;
    }
};