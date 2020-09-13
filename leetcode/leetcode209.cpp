// 這題除了prefix sum
// 還混了雙指針的用法，因為都是正數 所以有單調性
// 固定好右邊指針之後
// 把左邊指針固定在當前可容許的最大視窗 起點
// 一邊檢查總和有沒有 >= s
// 一邊把窗口縮小
// 時間複雜度 O(n)：因為每個元素頂多被訪問兩次
int minSubArrayLen(int s, vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int cursum = 0, len = nums.size() + 1, left = 0;
    for(int right = 0; right < nums.size(); right++) {
        cursum += nums[right];
        while(cursum >= s) {
            len = min(len, right - left + 1);
            cursum -= nums[left];
            left++;
        }
    }
    return (len == nums.size() + 1 ? 0 : len);
}