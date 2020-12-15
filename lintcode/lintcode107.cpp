/** 分解成子問題
 * 如果 'a' + 'b' 可以分解成字典中的單字
 * 代表 'a' 可以分解成字典中的單字
 * 然後 'b' 也是字典中的單字
 * 這就是這邊狀態轉移方程的意思
 * 這題其實也可以用dfs解，空間複雜度會比較低
 * 不過因為lintcode在這題上時間複雜度限制比較高
 * 所以用dfs很容易TLE
*/
class Solution {
public:
    /**
     * @param s: A string
     * @param wordSet: A dictionary of words dict
     * @return: A boolean
     * dp[i]: whether the substr(0, i) can be segmented to words in dictionary
     */
    bool wordBreak(string &s, unordered_set<string> &wordSet) {
        // write your code here
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            for(auto word : wordSet) {
                int len = word.length();
                if(i - len >= 0 && wordSet.count(s.substr(i - len, len)) != 0)
                    dp[i] = dp[i] || dp[i - len];
            }
        }
        
        return dp[n];
    }
};