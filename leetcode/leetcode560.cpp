// 應用到 prefix sum - interval sum 等於 以前的某個prefix sum 的觀念
// 使用 map 加速了搜尋以前某個 prefix sum 的過程
int subarraySum(vector<int>& nums, int k) {
    int cnt = 0;
    int sum = 0;
    // <sum, cnt>
    unordered_map<int, int> mp;
    mp[0]++;  // prefix_sum剛好等於k的情況
    for(int i : nums) {
        sum += i;
        if(mp[sum - k]) cnt += mp[sum - k];
        mp[sum]++;
    }
    return cnt; 
}

// 這裡給個lintcode上的變形題目
// 找出和為k的最短subarray
// 這裏概念跟上面差不多
// 一樣都是用map快速搜查以前的區間和
// 可是mp[0]的值不一樣
// map的定義：<sum, 前i個>
int subarraySumEqualsKII(vector<int> &nums, int k) {
    if(nums.size() == 0) return -1;
    int len = nums.size() + 1;
    int cursum = 0;
    // <sum, 前i個>
    map<int, int> mp;
    mp[0] = 0;
    for(int i = 0; i < nums.size(); i++) {
        cursum += nums[i];
        if(mp.count(cursum - k)) {
            len = min(len, i + 1 - mp[cursum - k]);
        }
        mp[cursum] = i + 1;
    }
    return len > nums.size() ? -1 : len;
}