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