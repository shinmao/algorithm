// 果然遞迴的思維很靠腦袋想像呀
// 仔細看看下面遞迴式考慮了所有可能
// lmax和rmax代表沒有root的情況下子樹的最大值
// sum則是去比較如果選了root和左子右子的情況會不會比較厲害
// 最後return的地方則是在每一次check子樹的極值時都看看要不要加root
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
