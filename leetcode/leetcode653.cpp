// 雖然看似沒有那麼理想
// 但是練習recursion思維的好機會
// AC 64.16%
unordered_set<int> s;
bool findTarget(TreeNode* root, int k) {
    if(!root) return false;
    if(s.count(k - root->val)) return true;
    s.insert(root->val);
    return findTarget(root->left, k) || findTarget(root->right, k);
}

// 這個solution看起來應該是最快的了
// 先用inorder把tree traverse一遍放入一個陣列
// 為了後來在搜目標時利用單調性，我們直接用inorder來traverse
// while這邊用的不是二分法，但是卻是線性時間的方法
// 如果硬要用binary search大概會O(nlogn)吧
// AC 95.07%
vector<int> v;
void inorder(TreeNode* root) {
    if(!root) return;
    inorder(root->left);
    v.push_back(root->val);
    inorder(root->right);
}

bool findTarget(TreeNode* root, int k) {
    inorder(root);
    int start = 0, end = v.size() - 1;
    while(start < end) {
        if(v[start] + v[end] == k) return true;
        if(v[start] + v[end] < k) ++start;
        else --end;
    }
    return false;
}