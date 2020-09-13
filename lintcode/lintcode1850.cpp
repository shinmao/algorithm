// 用隔板法
// 分兩種情況討論：左邊k右邊l / 左邊l右邊k
// 這邊在自己寫的getApple裡面用sliding window求最大窗口，所以還要傳入window size
int getApple(vector<int> &a, int winsize, int left, int right) {
    int maxApple = 0;
    if(winsize > right - left)
        return -1;
    for(int i = left; i < left + winsize; i++)
        maxApple += a[i];
    int apples = maxApple;
    for(int i = left + 1; i <= right - winsize; i++) {
        apples = apples - a[i - 1] + a[i + winsize - 1];
        maxApple = max(maxApple, apples);
    }
    return maxApple;
}

int PickApples(vector<int> &A, int K, int L) {
    int maxApple = INT_MIN;
    for(int i = 0; i < A.size(); i++) {
        // k left l right
        int leftk = getApple(A, K, 0, i);
        int rightl = getApple(A, L, i, A.size());
        // l left k right
        int leftl = getApple(A, L, 0, i);
        int rightk = getApple(A, K, i, A.size());
        
        if(leftk != -1 && rightl != -1)
            maxApple = max(maxApple, leftk + rightl);
        if(leftl != -1 && rightk != -1)
            maxApple = max(maxApple, leftl + rightk);
    }
    if(maxApple == INT_MIN)
        return -1;
    return maxApple;
}