// 唉呀！這題連學校都教過呢！
// 這樣的走法 向下走和向右走的數量最多就O(n+m)而已
vector<int> findPeakII(vector<vector<int>> &A) {
    int n = A.size();
    int m = A[0].size();
    
    int i = 1, j = 1;
    
    for(; 1; i++) {
        while(A[i][j] < A[i][j + 1])
            j++;
        while(A[i][j] < A[i][j - 1])
            j--;
        if(A[i][j] > A[i + 1][j] && A[i][j] > A[i - 1][j])
            return vector<int>{i, j};
    }
    
    return vector<int>{-1, -1};
