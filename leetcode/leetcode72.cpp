/**
 * 這個解法基本case可以通過
 * 但當case長度比較大時容易TLE
 * 當 idx i 和 idx j 的字符不一樣時
 * insert: 在word[i]後面插入word[j]，因此i停留在原地，j比對完成然後往前移
 * del: 把word[i]刪掉，因此i往前移，j停留在原地
 * replace: 把word[i]直接換成word[j]，因此兩個比對完成，一起往前移
 * 別忘記操作數+1
 * base case:
 * i和j其中一個為-1，代表其中一個字串跑完了
 * 剩下的直接插入就好，因此return idx + 1
 */
class Solution {
public:
    /**
    * return edit distance between word1[0..i] and word2[0..j]
    * there are four types of operation: insert, del, rel, skip
    */
    int dp(string word1, string word2, int i, int j) {
        if(i == -1)
            return j + 1;
        if(j == -1)
            return i + 1;
        // if two char are same, skip
        if(word1[i] == word2[j]){
            return dp(word1, word2, i - 1, j - 1);
        }else {   // if two chars are not same
            return min( dp(word1, word2, i, j - 1) + 1  // insert word2[j] after word1[i]
                , min( dp(word1, word2, i - 1, j) + 1,   // delete word1[i]
                dp(word1, word2, i - 1, j - 1) + 1)        // replace word1[i] with word2[j]
            );
        }
        return 0;
    }
    
    int minDistance(string word1, string word2) {
        if(word1.size() == word2.size()){
            if(word1.size() == 0)
                return 0;
        }
        
        return dp(word1, word2, word1.size() - 1, word2.size() - 1);
    }
};
/**
 * 優化：其實dp(i, j)存在大量的重複子問題，所以我們可以把計算過的結果存起來
 * 用dp[i][j]來存結果
 * dp[0][0] 代表 "" 與 "" 的編輯距離
 * 上下套路基本都一樣
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // base case for j = 0
        for(int i = 0; i <= m; i++)
            dp[i][0] = i;
        // base case for i = 0
        for(int j = 0; j <= n; j++)
            dp[0][j] = j;
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i - 1] == word2[j - 1]){   // 注意這邊dp array idx是從1開始，所以我們要減一
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    dp[i][j] = min(
                        dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1)
                    );
                }
            }
        }
        
        return dp[m][n];
    }
};
/** 如果是想輸出整個編輯過程呢？
 * 那我們就把dp[][]裏存的int換成一個帶有操作資訊的class就好
 * e.g. node.val = dist, node.choice = 0 -> skip操作
 * 然後我們可以從dp[m][n]一步步退回最一開始的dp[0][0]
 */