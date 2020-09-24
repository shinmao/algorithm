// 這題屬於區間型的動態規劃
// 前面dp的定義還算蠻好理解的
// 但要注意的是中間點k不能用枚舉的
// 只要算算看就會發現後區間很容易會出現前面還沒計算到的
// 這種時候常用的解法就是用長度枚舉
// 起點加長度也能得到終點
// 另外在計算cost的時候最後加上的merge sum一律等於區間內石頭的總和
// 所以可以用prefix sum先把區間和算好
// 除了枚舉長度還有另外一種方法
// 就是我們的i用倒著循環的
// 這樣也能間接限制長度
// 畢竟就是因為我們一開始的起點和終點的範圍就開最大了才出現的問題
int stoneGame(vector<int> &A) {
    // dp[i][j]: the minimum cost of merging the ith and the jth pile
    // dp[i][j] = dp[i][k] + dp[k + 1][j] + sum(i, j)
    // i <= k < j
    int n = A.size();
    if(n < 1)
        return 0;
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    vector<int> prefix_sum(A.size() + 1, 0);
    
    // calculate prefix sum of array
    for(int i = 0; i < n; i++)
        prefix_sum[i + 1] = prefix_sum[i] + A[i];
    
    // cost would be 0 if merge with self
    for(int i = 0; i < n; i++) 
        dp[i][i] = 0;
    
    // inclusive l
    for(int l = 2; l <= n; l++) {
        for(int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;
            int sum = prefix_sum[j + 1] - prefix_sum[i];
            for(int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum);
        }
    }
    
    return dp[0][n - 1];
}

// 區間型動態規劃有一個很有名的優化方式
// 叫 四邊形不等式優化 (quadrangle inequality optimization)
// 我們多開了一個數組紀錄之前的最優切割點
// e.g. 長度為3時 我們得到了[2, 5]切割點最優為3，[3, 6]切割點最優為5
// 那麼長度為4時，[2, 6]的最優切割點將會>= 3 && <= 5
// 這要用歸納法證明，在面試的時候不重要
// 不過大幅度縮短了我們枚舉k的時間
// 不過還有不一樣的地方
// 這次我們得自己優化長度為2的區間
// cut[i][i + 1]的值必須我們自己初始化
int stoneGame(vector<int> &A) {
    // dp[i][j]: the minimum cost of merging the ith and the jth pile
    // dp[i][j] = dp[i][k] + dp[k + 1][j] + sum(i, j)
    // i <= k < j
    int n = A.size();
    if(n < 1)
        return 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> cut(n, vector<int>(n, 0));
    vector<int> prefix_sum(A.size() + 1, 0);

    // calculate prefix sum of array
    for(int i = 0; i < n; i++)
        prefix_sum[i + 1] = prefix_sum[i] + A[i];

    // length of 2
    for(int i = 0; i < n - 1; i++) {
        dp[i][i + 1] = A[i] + A[i + 1];
        cut[i][i + 1] = i;
    }

    // inclusive l
    for(int l = 3; l <= n; l++) {
        for(int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            int sum = prefix_sum[j + 1] - prefix_sum[i];
            for(int k = cut[i][j - 1]; k <= cut[i + 1][j]; k++) {
                if(dp[i][j] > dp[i][k] + dp[k + 1][j] + sum) {
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + sum;
                    cut[i][j] = k;
                }
            }
        }
    }

    return dp[0][n - 1];

// 接下來這道是Lintcode 593
// 上面 stone game 變成一個環
// 這種list變成circle的題目最適合的作法就是把陣列在複製一次就好
// 大部分跟上面的都一樣，只是size變兩倍
// dp prefix_sum的定義都跟上面一樣
// 注意到最後一個part
int stoneGame2(vector<int> &A) {
    int n = A.size();
    if(n < 1)
        return 0;
    vector<vector<int>> dp(2*n, vector<int>(2*n, INT_MAX));
    vector<int> prefix_sum(2*n + 1, 0);
    
    prefix_sum[0] = 0;
    for(int i = 1; i <= 2*n; i++)
        prefix_sum[i] = prefix_sum[i - 1] + A[(i - 1) % n];
    
    for(int i = 0; i < 2*n; i++) 
        dp[i][i] = 0;
    
    for(int l = 2; l <= n; l++) {
        for(int i = 0; i < 2*n - l + 1; i++) {
            int j = i + l - 1;
            int sum = prefix_sum[j + 1] - prefix_sum[i];
            for(int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum);
        }
    }
    
    // 這裡是唯一不一樣的地方
    // 變成一個環代表在這個circle裡面只要能繞一圈就好
    // 所以我們要枚舉起點 長度為n的最小cost區間
    int res = INT_MAX;
    for(int i = 0; i < n; i++)
        res = min(res, dp[i][i + n - 1]);
    
    return res;
}
