// beats only 13%
class BSTIterator {
    stack<TreeNode *> tree;
private:
    void pushAll(TreeNode* node){
        for(; node != NULL; tree.push(node), node = node->left);
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* top = tree.top();
        tree.pop();
        pushAll(top->right);
        return top->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !tree.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */