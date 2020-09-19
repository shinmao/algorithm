// 這題看題目就像是要修改tree結構的題目
// 還要求挑戰deleteNode在常數時間內完成
// 其實用一個淫巧就可以解決修改的麻煩
// lazy delete 不用真的把node刪掉，而是用紀錄的
// 所以traverse的時候只要去看節點有沒有被刪掉
// 而且也可以解決 單節點刪除不會影響他下面繼承人資格的問題
private:
    int val;
    bool deleted;
    set<MyTreeNode*> child;
public:
    /**
     * @param val: the node's val
     * @return: a MyTreeNode object
     */
    MyTreeNode(int val) {
        this->val = val;
        this->deleted = false;
    }
    
    /**
     * @param root: the root treenode
     * @return: get the traverse of the treenode
     */
    vector<int> traverse(MyTreeNode * root) {
        vector<int> res;
        if(!root)
            return res;
        
        if(!root->deleted)
            res.push_back(root->val);
        for(auto c : root->child) {
            for(auto t : traverse(c))
                res.push_back(t);
        }
        
        return res;
    }

    /**
     * @param root: the node where added
     * @param value: the added node's value
     * @return: add a node, return the node
     */
    MyTreeNode * addNode(MyTreeNode * root, int value) {
        MyTreeNode * newchild = new MyTreeNode(value);
        root->child.insert(newchild);
        return newchild;
    }

    /**
     * @param root: the deleted node
     * @return: nothing
     */
    void deleteNode(MyTreeNode * root) {
        root->deleted = true;
    }
};
