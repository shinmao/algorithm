/**
 * 盲點：題目要求的是回傳最大的root，可是要return數字才能比較呀
 * 這樣到底要怎麼return呢？
 * 思路：自己定義return type
 */
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    struct Result {
        int sum;
        int count;
        Result(int s = 0, int c = 0): sum(s), count(c) {};
    };
    
    Result maxNode_Res = Result();
    TreeNode * maxNode;
    
    Result dfs(TreeNode * root) {
        if(root == NULL)
            return Result();
        
        Result l_res = dfs(root->left);
        Result r_res = dfs(root->right);
        Result res = Result(l_res.sum + r_res.sum + root->val, l_res.count + r_res.count + 1);
        
        /** 這裡是在算以當前節點為root的subtree平均是否大於目前最大平均
         * 一開始覺得很奇怪為何是這樣的算法
         * 後來發現是交叉乘法
         * (res.sum / res.count) > (maxNode_Res.sum / maxNode_Res.count)
         * 為了避免精度問題
         * 可以換成 下面這個乘法的樣子
         */
        if(maxNode_Res.count == 0 || res.sum * maxNode_Res.count > res.count * maxNode_Res.sum) {
            maxNode_Res = res;
            maxNode = root;
        }
        
        return res;
    }
    
    TreeNode * findSubtree2(TreeNode * root) {
        if(root == NULL)
            return NULL;
        dfs(root);
        return maxNode;
    }
};