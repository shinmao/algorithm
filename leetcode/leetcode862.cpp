// 這題沒有單調性，又要大於等於k，又要求最短，又說n^2會TLE 媽的
// 但是你敢信，這題我們就用單調性解
// 我們的單調用deque實現(為了方便從兩端操作)，裡面維護的是prefix sum對應到的index(這樣就可以比較長度)
// 仔細想想 我們全部的prefix sum的確沒有單調性
// 但是要解這題我們只需要留下單調成長的prefix sum呀
// e.g. A B C 現在A B C是三個連續的prefix sum，然後B < A < C
// 如果我要看他們 prefix sum 有沒有大於k，我真的需要在意B嘛
// 不用我只要看A就好，因為A如果都小於k的話，B也一定小於呀
// 所以我們只要維持一個單調成長的 prefix sum，然後跟 k 比較就好
int shortestSubarray(vector<int>& A, int K) {
    if(A.size() == 0) return -1;
    int len = A.size() + 1;
    deque<int> dq;
    vector<int> prefix(A.size() + 1);
    for(int i = 1; i <= A.size(); i++)
        prefix[i] = prefix[i - 1] + A[i - 1];
    for(int i = 0; i <= A.size(); i++) {
        while(!dq.empty() && prefix[i] - prefix[dq.front()] >= K)
            len = min(len, i - dq.front()), dq.pop_front();
        while(!dq.empty() && prefix[i] <= prefix[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    return len > A.size() ? -1 : len;
}