/**
 * 首先讓子問題獨立：
 * 如果我們將dp[i]定義為戳破前i個氣球的最大點數
 * 很明顯的，戳破dp[i]和dp[i + 1]是會互相影響的
 * 我們把問題轉化一下：
 * 加上頭和尾的兩顆虛擬氣球
 * 現在氣球的index變成0~n+1
 * 我們要把整排氣球戳破，最後剩下0和n+1
 */
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        vector<int> balls(n + 2, 1);
        for(int i = 1; i <= n; i++)
            balls[i] = nums[i - 1];
        
        // dp[i][j]: maximum coin got after bursting balloons between ith and jth
        // not include ith and jth (所以dp數組定義的是開區間)
        // 狀態轉移方程很巧妙，指定最後一個戳破的氣球
        // 如果最後一個戳破的氣球是kth
        // dp[i][j] = dp[i][k] + dp[k][j] + balls[i]*balls[k]*balls[j]
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        // 上面的狀態轉移方程搞出來後
        // dp依賴的必須是以前已經被計算出答案的狀態
        // 這會決定我們的遍歷順序(畫個圖會發現要用對角線遍歷，這邊我們由下往上遍歷來取代)
        // 首先我們j >= i
        
        // base case for i == j
        // 由於開區間，這代表區間內沒有任何一個氣球可以讓我們爆
        for(int i = 0; i <= n + 1; i++)
            dp[i][i] = 0;
        
        // 由下往上遍歷
        for(int i = n; i >= 0; i--) {
            for(int j = i + 1; j <= n + 1; j++) {
                for(int k = i + 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + balls[i]*balls[k]*balls[j]);
                }
            }
        }
        
        return dp[0][n + 1];
    }
};