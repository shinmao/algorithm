// sync_with_stdio and cin.tie help me enhance from 39% to 84%
// beats over 84.99% of submission
class BIT {
public:
    vector<int> tree;
    int n = 0;
    BIT(int sz) {
        n = sz;
        tree.assign(n + 1, 0);
    }
    void update(int i, int up) {
        i++;
        while(i <= n){
            tree[i] += up;
            i += i&-i;
        }
    }
    int sumquery(int i) {
        i++;
        int sum = 0;
        while(i > 0){
            sum += tree[i];
            i -= i&-i;
        }
        return sum;
    }
};
class NumArray {
public:
    BIT tree;
    vector<int> num;
    NumArray(vector<int>& nums):tree(nums.size()) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        num = move(nums);
        for(int i = 0; i < num.size(); ++i)
            tree.update(i, num[i]);
    }
    
    void update(int i, int val) {
        tree.update(i, val - num[i]);
        num[i] = val;
    }
    
    int sumRange(int i, int j) {
        return tree.sumquery(j) - tree.sumquery(i-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */


// idea: Segment tree
// 76 ms
class NumArray {
private:
    vector<int> input;
    struct node {
        int val;
        node* l;
        node* r;
        node(int v=0): val(v){}
        node(node* l, node* r): l(l), r(r){ pull(); }
        void pull(){ val = l->val + r->val; }
    };
public:
    node* seg;
    node * build(int start, int end) {
        if(start + 1 == end) return new node(input[start]);
        int mid = start + (end - start)/2;
        return new node(build(start, mid), build(mid, end));
    }
    
    NumArray(vector<int>& nums) {
        if(nums.size() != 0) {
            input.assign(nums.begin(), nums.end());
            seg = build(0, input.size());
        }
    }
    
    void updateUtil(node* seg, int start, int end, int pos, int val) {
        if(start + 1 == end) {  seg->val = val; return; }
        int mid = start + (end - start)/2;
        if(pos < mid)
            updateUtil(seg->l, start, mid, pos, val);
        else
            updateUtil(seg->r, mid, end, pos, val);
        seg->pull();
    }
    
    void update(int i, int val) {
        if(i < 0 or i >= input.size()) return;
        updateUtil(seg, 0, input.size(), i, val);
    }
    
    int sumUtil(node* seg, int start, int end, int qs, int qe) {
        if(qs >= end or qe <= start) return 0;
        if(qs <= start and qe >= end) return seg->val;
        int mid = start + (end - start)/2;
        return sumUtil(seg->l, start, mid, qs, qe) + sumUtil(seg->r, mid, end, qs, qe);
    }
    
    int sumRange(int i, int j) {
        return sumUtil(seg, 0, input.size(), i, j + 1);
    }
};

// zkw segment tree
// beats over 92.97% of submission!
class NumArray {
private:
    int n;
    vector<int> seg;
    void build(vector<int>& nums) {
        for(int i = n; i < 2*n; ++i) 
            seg[i] = nums[i - n];
        for(int i = n-1; i > 0; --i)
            seg[i] = seg[i << 1] + seg[i << 1 | 1];
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.assign(2*n, 0);
        build(nums);
    }
    
    inline void update(int i, int val) {
        int k = val - seg[i + n];
        for(i += n; i > 0; i >>= 1) seg[i] += k;
    }
    
    // <start, end>
    // start: if left, include itself and right;
    // if right, include itself
    // end: if left, include itself
    // if right, include itself and left
    int sumRange(int i, int j) {
        int sum = 0;
        i += n; j += n;
        for(; i <= j; i >>= 1, j >>= 1) {
            if((i & 1)) sum += seg[i++];
            if(!(j & 1)) sum += seg[j--];
        }
        return sum;
    }
};