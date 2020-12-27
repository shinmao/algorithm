// 背包問題的變種
// 雖然沒有很明確的說背包容量或價值之類的
// 不過子集總和為整個總和的一半其實就可以轉換為背包問題了
// dp先確認狀態和選擇
// 狀態：剩餘可以填補的總和，可以選擇的數字
// 選擇：目前的數字放/不放入子集
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        for(auto num : nums)
            total_sum += num;
        
        if(total_sum % 2 != 0)
            return false;
        
        int sum = total_sum / 2;
        int n = nums.size();
        /*
        * dp[i][sum]: return true if first i nums have sum as sum
        * if pick up the num,
        * dp[i][j] = dp[i - 1][j - nums[i - 1]]
        * if not pick up the num,
        * dp[i][j] = dp[i - 1][j]
        */
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        
        // base case for j = 0
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                if(j >= nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
                }else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
};
// 一樣考慮壓縮
// 因為每個 [i] 都只跟前面的 [i - 1] 有關聯
// dp[j] 相當於 dp[i - 1][j]
// 不過要注意 j 遍歷的順序
// 因為 dp[j]會依賴dp[j - nums[i]]的緣故
// 本來 dp[j - nums[i]] 其實是 dp[i - 1][j - nums[i]] 前一輪的結果
// 但因為我們進行壓縮 若是j從前往後遍歷
// 那我們就會更改到 dp[j - nums[i]]的結果
// 改成 j從後往前遍歷的話 就不會有影響了！
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        for(auto num : nums)
            total_sum += num;
        
        if(total_sum % 2 != 0)
            return false;
        
        int sum = total_sum / 2;
        int n = nums.size();
        /*
        * dp[i][sum]: return true if first i nums have sum as sum
        * if pick up the num,
        * dp[i][j] = dp[i - 1][j - nums[i - 1]]
        * if not pick up the num,
        * dp[i][j] = dp[i - 1][j]
        */
        vector<bool> dp(sum + 1, false);
        
        dp[0] = true;
        for(int i = 0; i < n; i++) {
            for(int j = sum; j >= 0; j--) {
                if(j - nums[i] >= 0) {
                    dp[j] = dp[j] | dp[j - nums[i]];
                }
            }
        }
        
        return dp[sum];
    }
};
