## Segment tree
| Problem        | Source           | Writeup  |
| ------------- |:-------------:| -----:|
| Range Sum Query and Point Modified        | [struct implementation](RSQ-with-Node.cpp)      | This solution is ezier to understand, but use more memory than integer type |
|         | [array implementation](RSQ-with-Arr.cpp)      |  use the feature of index relationship between parent(x) and childs(`2*x` and `2*x+1`) |
| Range Sum Query and Point Modified    | [zkw](./PM-RSQ-with-zkw.cpp)      |   |
| Single Point Query and Interval Modified     | [zkw](./RM-SQ-with-zkw.cpp)      |   |

> I get several times of wrong answer on codefordce, and finally find that the value of node might cause to integer overflow. Therefore I change int to long long...

### Lintcode 439. Segment Tree Build II
```cpp
class Solution {
public:
    SegmentTreeNode * build(vector<int> &A) {
        return buildST(0, A.size() - 1, A);
    }
    
    SegmentTreeNode * buildST(int l, int r, vector<int> &A) {
        if(l > r) return NULL;
        SegmentTreeNode * node = new SegmentTreeNode(l, r, A[l]);
        if(l == r) return node;
        int m = (l + r)/2;
        node->left = buildST(l, m, A);
        node->right = buildST(m+1, r, A);
        // start merging information after recursion
        node->max = max(node->left->max, node->right->max);
        return node;
    }
};
```

### Lintcode 203. Single point Modify
```cpp
class Solution {
public:
    void modify(SegmentTreeNode * root, int index, int value) {
        if(root == NULL or index < root->start or index > root->end) return;
        if(root->start == root->end) {
            root->max = value; 
            return;
        }
        if(index <= root->left->end)
            modify(root->left, index, value);
        else
            modify(root->right, index, value);
        root->max = max(root->left->max, root->right->max);
    }
};
```

## Lazy tag

### Interval modified
```cpp
// [a, b]: query for interval
// i: node index
// [l, r]: interval of current node
// x: updated value
void add(int a, int b, int i, int l, int r, int x) {
    if(a <= l and b >= r) t[i].chg += x;
    else if(a > r or b < l) return;
    else {
        int m = (l + r)/2, lc = i*2 + 1, rc = i*2 + 2;
        add(a, b, lc, l, mid, x);
        add(a, b, rc, mid+1, r, x);
        t[i].data = max(t[lc].data + t[lc].chg, t[rc].data + t[rc].chg);
    }
}
```

### Interval query
```cpp
int query(int a, int b, int i, int l, int r) {
    if(a <= l and b >= r) return t[i].data + t[i].chg;
    else if(a > r or b < l) return -1;
    else {
        int m = (l + r)/2, lc = i*2 + 1, rc = i*2 + 2;
        int x1 = query(a, b, lc, l, m);
        int x2 = query(a, b, rc, m+1, r);
        return max(x1, x2) + t[i].chg;
    }
}
```