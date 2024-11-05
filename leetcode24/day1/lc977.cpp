class Solution {
// 這題其實我也有想出two ptr的解法
// 但一直卡在我想找到第一個正數的位置，然後往兩邊visit
// 這樣把實現搞得很複雜
// 不妨換個角度想，如果我們是要從大輸入到小呢？
// 只要先宣告一定大小的陣列就好
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size() - 1;
        vector<int> res(nums.size(), 0);
        for (int i = 0, j = nums.size() - 1; i <= j;) {
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                res[k--] = nums[j] * nums[j];
                j--;
            } else {
                res[k--] = nums[i] * nums[i];
                i++;
            }
        }
        
        return res;
    }
};