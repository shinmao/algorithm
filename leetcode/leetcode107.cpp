/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root != NULL) q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int> level;
            while(len > 0){
                TreeNode* head = q.front();
                q.pop();
                level.push_back(head->val);
                if(head->left != NULL){
                    q.push(head->left);
                }
                if(head->right != NULL){
                    q.push(head->right);
                }
                len--;
            }
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};