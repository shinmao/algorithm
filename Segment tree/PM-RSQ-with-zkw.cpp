#include <bits/stdc++.h>
using namespace std;

const int N = 1e5; // limit for array size
int n;   // array size
int t[2 * N];

void build() {
    for(int i = n - 1; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
}

inline void modify(int p, int val) {
    for(t[p += n] = val; p > 1; p >>= 1) t[p >>= 1] = t[p] + t[p ^ 1];
}

// if l is left child, then it include itself and right child; otherwise, it only include right child
// if r is right child, it only include left child 
int query(int l, int r) {   // [l, r)
    int sum = 0;
    for(l += n, r += n; l <= r; l >>= 1, r >>= 1) {
        if(l & 1) sum += t[l++];
        if(r & 1) sum += t[--r];
    }
    return sum;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> t + n + i;
    build();
    modify(p, val);
    return 0;
}