#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int getMid(int s, int e) { return s + (e-s)/2; }

void updateValUtil(long long *st, int start, int end, int idx, long long dif, int cur_idx) {
    if(idx < start or idx > end) return;
    st[cur_idx] += dif;
    if(start != end) {
        int mid = getMid(start, end);
        updateValUtil(st, start, mid, idx, dif, 2*cur_idx + 1);
        updateValUtil(st, mid+1, end, idx, dif, 2*cur_idx + 2);
    }
}

long long getSumUtil(long long *st, int start, int end, int ql, int qr, int cur_idx) {
    if(ql <= start and qr >= end) return st[cur_idx];
    if(qr < start or ql > end) return 0;
    int mid = getMid(start, end);
    return getSumUtil(st, start, mid, ql, qr, 2*cur_idx + 1)
        + getSumUtil(st, mid+1, end, ql, qr, 2*cur_idx + 2);
}

void update(long long input[], long long *st, int n, int idx, long long new_val) {
    // check -> update
    if(idx < 0 or idx > n-1) return;
    long long dif = new_val - input[idx];
    input[idx] = new_val;
    updateValUtil(st, 0, n-1, idx, dif, 0);
}

long long getSum(long long *st, int n, int ql, int qr) {
    // check -> get sum
    if(ql < 0 or qr > n-1 or ql > qr) return -1;
    return getSumUtil(st, 0, n-1, ql, qr, 0);
}

long long build(long long input[], int start, int end, long long *st, int cur_idx) {
    if(start == end) {
        st[cur_idx] = input[start];
        return input[start];
    }
    int mid = getMid(start, end);
    st[cur_idx] = build(input, start, mid, st, cur_idx*2 + 1)
            + build(input, mid+1, end, st, cur_idx*2 + 2);
    return st[cur_idx];
}

// allocate memory for seg tree
long long *allocate(long long input[], int n) {
    // height of tree
    int x = (int)(ceil(log2(n)));
    // max size of tree
    int max_size = 2*(int)pow(2, x) - 1;
    long long *st = new long long[max_size];
    build(input, 0, n-1, st, 0);
    return st;
}

int main() { _
    int n, m;
    cin >> n >> m;
    long long *input = new long long[n];
    for(int i = 0; i < n; ++i) cin >> input[i];
    long long *st = allocate(input, n);
    while(m != 0) {
        vector<int> op(3);
        for(int i = 0; i < op.size(); ++i) cin >> op[i];
        if(op[0] == 1) {
            update(input, st, n, op[1], op[2]);
        }else if(op[0] == 2) {
            cout << getSum(st, n, op[1], op[2] - 1);
            if(m != 1) cout << '\n';
        }
        m--;
    }
    return 0;
}