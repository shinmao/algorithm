/**
 * 第一種解法：dfs暴力破解
 * 不過會撐破lc的時間複查度
 */
class Solution {
public:
    int ans = 0;
    void dfs(vector<int>& nums, int cur_idx, int rest_sum) {
        if(cur_idx == nums.size()) {
            if(rest_sum == 0) {
                ans++;
            }
            return;
        }

        // if choose -
        rest_sum += nums[cur_idx];
        dfs(nums, cur_idx + 1, rest_sum);
        rest_sum -= nums[cur_idx];
        
        // if choose +
        rest_sum -= nums[cur_idx];
        dfs(nums, cur_idx + 1, rest_sum);
        rest_sum += nums[cur_idx];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0)
            return 0;
        
        dfs(nums, 0, S);
        return ans;
    }
};

/**
 * 第二種解法：DP
 * 不計算重複的子問題
 * 狀態用(目前idx,剩下的總和)表示
 * 不過某些dp存的result會interger overflow
 */
class Solution {
public:
    // <(current_index, rest_sum), result>
    unordered_map<string, int> memo;
    int dp(vector<int>& nums, int cur_idx, int rest_sum) {
        if(cur_idx == nums.size()) {
            if(rest_sum == 0)
                return 1;
            return 0;
        }
        
        string key = to_string(cur_idx) + "," + to_string(rest_sum);
        // if the answer of subproblem is get already
        if(memo.count(key))
            return memo[key];
        
        int result = dp(nums, cur_idx + 1, rest_sum - nums[cur_idx]) + dp(nums, cur_idx + 1, rest_sum + nums[cur_idx]);
        memo[key] = result;
        return result;
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0)
            return 0;
        
        return dp(nums, 0, S);
    }
};

/**
 * 這題換個思路就可以把題目變成背包問題
 * 尋找子集總和為目標總和的方法數
 * 不過我在integer overflow方面的問題跳了好幾次坑
 * 加總的時候很可能會溢位
 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        if(n == 0)
            return 0;
        
        /**
         * if + belongs to set pos
         * if - belongs to set neg
         * sum(pos) - sum(neg) = S
         * sum(pos) = S + sum(neg)
         * 2 * sum(pos) = S + sum(nums)
         * 存在一個pos set，sum為 (S + sum(nums)) / 2
         * 背包問題
        */
        int sum = 0;
        for(int i: nums)
            sum += i;
        
        if((sum + (long)S) % 2 != 0 || sum < S)
            return 0;
        
        int target = (sum + S) / 2;
        /**
         * dp[i][sum]: feasible ways for first i numbers to sum up as sum
         * if pick the number
         * dp[i][sum] = dp[i - 1][sum - current_num]
         * if not pick
         * dp[i][sum] = dp[i - 1][sum]
         */
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        // base case for j = 0
        // no any nums belong to positive set
        // all nums belong to negative set
        for(int i = 0; i <= n; i++) 
            dp[i][0] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= target; j++) {
                if(j - nums[i - 1] >= 0) 
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        
        return dp[n][target];
    }
};

/**
* 老樣子狀態壓縮囉
* 瞬間變成beats 9x%囉
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        if(n == 0)
            return 0;
        
        /**
         * if + belongs to set pos
         * if - belongs to set neg
         * sum(pos) - sum(neg) = S
         * sum(pos) = S + sum(neg)
         * 2 * sum(pos) = S + sum(nums)
         * 存在一個pos set，sum為 (S + sum(nums)) / 2
         * 背包問題
        */
        int sum = 0;
        for(int i: nums)
            sum += i;
        
        if((sum + (long)S) % 2 != 0 || sum < S)
            return 0;
        
        int target = (sum + S) / 2;
        /**
         * dp[i][sum]: feasible ways for first i numbers to sum up as sum
         * if pick the number
         * dp[i][sum] = dp[i - 1][sum - current_num]
         * if not pick
         * dp[i][sum] = dp[i - 1][sum]
         */
        vector<int> dp(target + 1, 0);

        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = target; j >= 0; j--) {
                if(j - nums[i] >= 0) 
                    dp[j] += dp[j - nums[i]];
            }
        }
        
        return dp[target];
    }
};