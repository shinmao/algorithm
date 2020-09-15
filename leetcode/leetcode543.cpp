// 最大直徑不一定會穿過root
// 先考慮一般情況：左：1 + dfs(左)/右：1 + dfs(右)
// 可是若沒有左，那左邊連+1都不需要了，所以我會把+1放在判斷完null後面
int dfs(TreeNode* root, int& d) {  // 這邊注意depth要用指標傳，不然就要用全域
    if(root == nullptr)
        return 0;
    int left = dfs(root->left, d);
    int right = dfs(root->right, d);
    d = max(d, left + right);  // 這裡先開始比較最大直徑
    return 1 + max(left, right);  // root到child之前的chain + child以下的chain
}

int diameterOfBinaryTree(TreeNode* root) {
    int d = 0;
    dfs(root, d);
    return d;
}