// 這題沒有單調性，又要大於等於k，又要求最短，又說n^2會TLE 媽的
// 但是你敢信，這題我們就用單調性解
// 我們的單調用deque實現(為了方便從兩端操作)，裡面維護的是prefix sum對應到的index(這樣就可以比較長度)
// 來解釋一下為何prefix sum有單調性
// 注意題目說 k >= 1，sum必為正數，然後我們又要最短的子數組
// 常理來講我們絕不會選擇從負數開始
// 要怎麼判定是不是負數呢？ prefix[idx] - prefix[idx - 1] 若是小於 0  不就代表這個idx上是負數嗎
// 所以當我們發現新進的 prefix sum是比較小的，就要pop back來維護單調性囉
int shortestSubarray(vector<int>& A, int K) {
    if(A.size() == 0) return -1;
    int len = A.size() + 1;
    deque<int> dq;
    vector<int> prefix(A.size() + 1);
    for(int i = 1; i <= A.size(); i++)
        prefix[i] = prefix[i - 1] + A[i - 1];
    for(int i = 0; i <= A.size(); i++) {
        // 前面檢查 sum 是否大於k，邊pop掉
        while(!dq.empty() && prefix[i] - prefix[dq.front()] >= K)
            len = min(len, i - dq.front()), dq.pop_front();
        while(!dq.empty() && prefix[i] <= prefix[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    return len > A.size() ? -1 : len;
}