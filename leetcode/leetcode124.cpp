/** 對於每個node
 *          r
 *      1 /  \
 *       n
 *    2 /  \ 3
 *     l    r
 * 我們都要考慮：
 * node->val e.g. 走了 1
 * node->val + dfs(node->left) e.g. 走了 1 -> 2...
 * node->val + dfs(node->right) e.g. 走了 1 -> 3...
 * node->val + dfs(node->left) + dfs(node->right): 走了 2 -> 3
 * 要注意一個小陷阱，若是負的那我們還寧願不走，0還比較大
 **/
private:
    int dfs(TreeNode* root, int& sum) {
        if(root == nullptr)
            return 0;
        
        // if not root
        int lmax = max(0, dfs(root->left, sum));
        int rmax = max(0, dfs(root->right, sum));
        // if root
        sum = max(sum, root->val + lmax + rmax);
        return root->val + max(lmax, rmax);
    }
public:
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        dfs(root, sum);
        return sum;
    }

// 事後解釋都很合理
// 所以自己推敲了一遍怎麼寫出這個code的思路
// 既然是用divide and conquer
// 就要區分什麼東西在conquer之後才能整合訊息
// 這題裡conquer之後才能與root + left child + right child比較
// 所以這部分要放在divide child 的訊息出來的後面
// 那麼子樹也是每一次都在考慮到底要不要加上root
// 可能還是覺得很奇怪 到底為何要return那樣的東西
// 注意這邊我們最終拿到的答案並不是從dfs的return value拿到的
// 而是內部的sum
// sum才是最終答案，return value也只是作為把兒子的資訊傳給父親的媒介
