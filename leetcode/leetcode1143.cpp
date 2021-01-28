/**
 * 序列型dp用於兩個陣列的二維數組
 * dp[i][j]：text1的前i個和text2的前j個
 */
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1 = text1.size(), t2 = text2.size();
        
        vector<vector<int>> dp(t1 + 1, vector<int>(t2 + 1, 0));
        for(int i = 1; i <= t1; i++) {
            for(int j = 1; j <= t2; j++) {
                // 若字符一樣，代表他一定在LCS中
                if(text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                // 若不一樣會有三種情況，也有可能這個字符就不隸屬於LCS
                // 但這樣的情況不用列入討論，因為一定比其他兩個情況小
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        
        return dp[t1][t2];
    }
};
/**
 * 由於都只需要鄰居的狀態，很明顯可以狀態壓縮
 * 需要儲存的狀態是dp[i - 1][j - 1]
 * 無法使用倒著遍歷的方法，因為我們也需要dp[i][j - 1]
 * 因此我們用一個變數pre_val儲存前一個狀態更新以前的值(dp[i][j - 1]更新以前的值)
 */
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1 = text1.size(), t2 = text2.size();
        int pre_val = 0, cur_val = 0;
        
        vector<int> dp(t2 + 1, 0);
        for(int i = 1; i <= t1; i++) {
            // pre_val stores the result of dp[i - 1][j - 1]
            pre_val = 0;
            for(int j = 1; j <= t2; j++) {
                cur_val = dp[j];
                if(text1[i - 1] == text2[j - 1])
                    dp[j] = pre_val + 1;
                else
                    dp[j] = max(dp[j], dp[j - 1]);
                pre_val = cur_val;
            }
        }
        
        return dp[t2];
    }
};