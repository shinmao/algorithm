#include <bits/stdc++.h>
using namespace std;

const int N = 1e5; // limit for array size
int n;   // array size
int t[2 * N];

void build() {
    for(int i = n - 1; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
}

void modify(int l, int r, int val) {
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l & 1) t[l++] += val;
        if(r & 1) t[--r] += val;
    }
}
 
int query(int p) {
    int res = 0;
    for(p += n; p > 0; p >>= 1) res += t[p];
    return res;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> t + n + i;
    build();
    return 0;
}