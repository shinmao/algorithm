// 這題是經典的樹上dp題
// 一開始一直想dfs（當然可以用dp做的話這題肯定不會過的= =
// 但是需要另外紀錄上一個節點有沒有被robbed
// 也就是要返回多個值 想一想好像python才能辦到
// 總不能修改class的member吧
// 這題可以用dp是因為父node的最大值可以由子node決定
// 仔細想想這題也不是路徑問題
// 下面我已經寫下dp的轉移方程了
// 而這裡dp[i]的定義為當前節點搶或不搶的最大值
// 這裏return value不需要放入參數
// 因為dp父節點所需的資訊只需要考子節點提供
private:
    vector<int> dfs(TreeNode* root) {
        // dp[0]代表當前節點不搶
        // dp[1]代表當前節點搶
        vector<int> dp(2, 0);
        if(root == nullptr)
            return dp;
        
        vector<int> ldp = dfs(root->left);
        vector<int> rdp = dfs(root->right);
        // 轉移方程：
        // 不搶當前節點代表最大值可以由子節點搶或不搶構成
        dp[0] = max(ldp[0], ldp[1]) + max(rdp[0], rdp[1]);
        // 搶當前節點代表最大值可以由子節點不搶的最大值構成
        dp[1] = root->val + ldp[0] + rdp[0];
        
        return dp;
    }
public:
    int rob(TreeNode* root) {
        vector<int> dp = dfs(root);
        return max(dp[0], dp[1]);
    }
