// 經典背包問題
// 一開始有考慮子集，不過時間複雜度高達指數級別
// dp定義為前i個物體是否和能夠剛好為sum
// 這邊sum便是原背包總和的一半了
// 如果sum為奇數，那直接回傳不可能
bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int i : nums)
        sum += i;

    if(sum % 2 != 0)
        return false;
    sum /= 2;

    // dp[i][j]: is it possible that first i sum with j ?
    vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum + 1, false));

    // sum為0永遠都是可能的，畢竟不選就好
    for(int i = 0; i <= nums.size(); i++)
        dp[i][0] = true;
    
    // 前0個物體，總不可能總和還能大於0吧
    for(int i = 1; i <= sum; i++)
        dp[0][i] = false;

    // dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j]
    // 只有兩種可能
    // 1. (i - 1)個物體的總和已經達標了，後面物體都不放就好
    // 2. 加上目前第i個物體總和剛好達標
    for(int i = 1; i <= nums.size(); i++) {
        for(int j = 1; j <= sum; j++) {
            dp[i][j] = (j >= nums[i-1] && dp[i-1][j-nums[i-1]]) || dp[i-1][j];
        }
    }

    return dp[nums.size()][sum];
}
// 一樣考慮優化
// 之前想說會修改到舊的值所以另外開了一個vector
// 可是其實不用
// 用同一個vector，然後從後面訪問過來就不會改到了
// 而且因為一維都在同一個vector操作
// 所以不用考慮什麼 i-1 的邊界狀況
bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int i : nums)
        sum += i;

    if(sum % 2 != 0)
        return false;
    sum /= 2;

    vector<bool> dp(sum + 1, false);
    dp[0] = true;

    for(int i = 0; i < nums.size(); i++) {
        for(int j = sum; j >= 0; j--) {
            if(j >= nums[i])
                dp[j] = dp[j] | dp[j - nums[i]];
        }
    }

    return dp[sum];
}
