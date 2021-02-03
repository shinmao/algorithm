/**
 * 思路：每一次都計算當前能跳到最遠的地方
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return true;
        
        int farest = 0;
        for(int i = 0; i < n - 1; i++) {
            farest = max(farest, i + nums[i]);
            // 代表碰到 0，沒辦法再前進了
            if(farest <= i)
                return false;
        }
        
        return farest >= n - 1;
    }
};