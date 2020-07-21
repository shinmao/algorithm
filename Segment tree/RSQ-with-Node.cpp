#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std; 

vector<long long> input;

struct Node {
    long long val;
    Node *left, *right;
    Node ( long long v ): val ( v ) {}
    Node(Node *left, Node *right): left(left), right(right){ pull(); }
    void pull() { val = left->val + right->val; }
};

Node* build(int l, int r) {
    if(l + 1 == r) return new Node(input[l]);
    int mid = l + (r - l)/2;
    return new Node(build(l, mid), build(mid, r));
}

void modify(Node *n, int l, int r, int pos, long long k) {  // modify value at idx pos to k
    if(l + 1 == r) { n->val = k; return; }
    int mid = l + (r - l)/2;
    if(pos < mid) modify(n->left, l, mid, pos, k);
    else modify(n->right, mid, r, pos, k);
    n->pull();
}

long long query(Node *n, int l, int r, int ql, int qr) {   // sum in [ql, qr)
    if(ql >= r or qr <= l) return 0;
    if(ql <= l and qr >= r) return n->val;
    int mid = l + (r - l)/2;
    return query(n->left, l, mid, ql, qr) + query(n->right, mid, r, ql, qr);
}

int main() { _
    int n, m;
    cin >> n >> m;
    input.assign(n, 0);
    for(int i = 0; i < n; ++i) cin >> input[i];
    Node *root = build(0, input.size());
    while(m--) {
        vector<int> op(3);
        for(int i = 0; i < 3; ++i) cin >> op[i];
        if ( op [0] == 1 )  
            modify ( root , 0 , input.size(), op [1], op [2]); 
        else if ( op[0] == 2 ) {    
            cout << query(root, 0, input.size(), op[1], op[2]);
            if(m != 0) cout << '\n';
        }
    }
    return 0;
}