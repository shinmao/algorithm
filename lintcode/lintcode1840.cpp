// s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j]
// 中間實在有太多boundary的情況
// 所以我把它做成 n*m 的陣列
// 第0行第0列的內容都是0
vector<vector<int>> matrixRestoration(int n, int m, vector<vector<int>> &after) {
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> b(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            a[i][j] = after[i - 1][j - 1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            b[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1];
            after[i - 1][j - 1] = b[i][j];
        }
    }
    return after;
}