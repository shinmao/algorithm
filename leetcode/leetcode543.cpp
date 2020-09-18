// 這題要小心：最大直徑不一定會穿過root
// 思路：
// M_D[node]: max diameter of node
// M_C[node]: max chain of node
// 以題目為例：
// 先想想 M_D[1] = M_D[2] + M_D[3]？
// 很明顯不是...
// 我們發現在root用M_D的思考方式，在他的child應該用M_C的思考方式
// M_D[root] = 1 + M_C[left] + 1 + M_C[right]
// M_C[child] = 1 + max(M_C[left], M_C[right]) (因為只能走一條路)
int dfs(TreeNode* root, int& d) {  // 這邊注意depth要用指標傳，不然就要用全域
    if(root == nullptr)
        return 0;
    int left = dfs(root->left, d);
    int right = dfs(root->right, d);
    d = max(d, left + right);
    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    int d = 0;
    dfs(root, d);
    return d;
}