// 子問題的定義跟原問題一樣
// 而且我們也想保留其他人選的顏色
// 所以需要二維
int minCost(vector<vector<int>>& costs) {
    if(costs.size() == 0)
        return 0;
    // dp[i][j]: min cost of painting i houses with ith of jth color
    vector<vector<int>> dp(costs.size(), vector<int>(3, INT_MAX));

    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];

    for(int i = 1; i < costs.size(); i++) {
        for(int j = 0; j < 3; j++) {
            if(j == 0) {
                dp[i][j] = min(dp[i-1][1], dp[i-1][2]) + costs[i][j];
            }else if(j == 1) {
                dp[i][j] = min(dp[i-1][0], dp[i-1][2]) + costs[i][j];
            }else {
                dp[i][j] = min(dp[i-1][0], dp[i-1][1]) + costs[i][j];
            }
        }
    }

    int ans = dp[costs.size() - 1][0];
    ans = min(ans, dp[costs.size() - 1][1]);
    ans = min(ans, dp[costs.size() - 1][2]);
    return ans;
}
// 覺得時間複雜度不夠好？
// 那就再優化就好呀
// 可以發現其實我們只需要前一個房子的資訊
// 所以其實dp裡面保留的只要一個就好
// 然後要訪問下一個房子之前
// 舊的資訊就用三個變數存起來就好
int minCost(vector<vector<int>>& costs) {
    if(costs.size() == 0)
        return 0;
    // dp[i][j]: min cost of painting i houses with ith of jth color
    vector<int> dp(3, 0);

    int c0 = costs[0][0];
    int c1 = costs[0][1];
    int c2 = costs[0][2];

    for(int i = 1; i < costs.size(); i++) {
        dp[0] = min(c1, c2) + costs[i][0];
        dp[1] = min(c0, c2) + costs[i][1];
        dp[2] = min(c0, c1) + costs[i][2];
        c0 = dp[0];
        c1 = dp[1];
        c2 = dp[2];
    }

    return min(c0, min(c1, c2));
}
