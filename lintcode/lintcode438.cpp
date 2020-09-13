int copyBooksII(int n, vector<int> &times) {
    if(n == 0 || times.size() == 0) return 0;
    int mi = INT_MAX, mx = 0;
    for(int t : times) {
        mi = min(mi, t);
        mx = max(mx, t);
    }
    int left = mi, right = mx*n;
    while(left + 1 < right) {
        int mid = left + ((right - left) >> 1);
        int cnt = 0;
        for(int t : times)
            cnt += mid/t;
        if(cnt >= n)
            right = mid;
        else
            left = mid;
    }
    int cnt1 = 0, cnt2 = 0;
    for(int t : times) {
        cnt1 += left/t;
        cnt2 += right/t;
    }
    if(cnt1 >= n) return left;
    if(cnt2 >= n) return right;
    return 0;
}