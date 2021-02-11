class Solution {
public:
    // 求先手是否會勝利
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        if(n == 2)
            return true;
        
        // dp[i][j] 為閉區間
        // dp[i][j][first]: [i...j]之間先手是否會勝利
        // dp[i][j][second]： [i...j]之間後手是否會勝利
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, make_pair(0, 0)));
        
        // base case if i == j
        // 那麼就只有一顆石頭，先手得分
        for(int i = 0; i < n; i++) {
            dp[i][i].first = piles[i];
            dp[i][i].second = 0;
        }
        
        // 狀態轉移方程：面對[i...j]，如果我作為先手
        // 先手選左邊那堆，那接下來剩下的區間就是[i+1...j]，可是我變成後手
        // 先手選右邊那堆，那接下來剩下的區間就是[i...j-1]，可是我變成後手
        // dp[i][j].first = max(piles[i] + dp[i+1][j].second, piles[j] + dp[i][j - 1].second)
        // 如果先手選擇左邊，dp[i][j].second = dp[i+1][j].first
        // 如果先手選擇右邊，dp[i][j].second = dp[i][j - 1].first
        
        // 接下來透過狀態轉移方程判斷一下遍歷順序
        for(int i = n - 2; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                // 先手最左邊那堆
                int left = piles[i] + dp[i + 1][j].second;
                // 先手最右邊那堆
                int right = piles[j] + dp[i][j - 1].second;
                if(left > right) {
                    dp[i][j].first = left;
                    dp[i][j].second = dp[i + 1][j].first;
                }else{
                    dp[i][j].first = right;
                    dp[i][j].second = dp[i][j - 1].first;
                }
            }
        }
        
        return dp[0][n - 1].first > dp[0][n - 1].second;
    }
};