// 定義還蠻好想的：dp[i][j] s的前i個能不能匹配上p的前j個
// 在寫這題還要注意OFB！！
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        
        dp[0][0] = true;
        // 若s為長度0，p只有可能給個*
        for(int j = 1; j <= p.size(); j++) {
            dp[0][j] = j > 1 && p[j - 1] == '*' && dp[0][j - 2];
        }
        // 最麻煩的分析部分
        // *可以匹配 0 個，也可以匹配多個，要怎麼一起討論呢？
        // 若是匹配 0 個，那就相當於把 "x*" 直接從p拆掉，所以只要看 dp[i][j-2]的情況
        // 若是匹配 >=1 個，這裏我們可能會想要把一個s[i - 1]連同 "x*"一起拔掉
        // 但是不行！最明顯的例子就是 "aa" v.s. "a*"
        // *不管是匹配 0 個還是 >= 1個，我們這樣拔掉分析都會導致原本能夠匹配的壞掉
        for(int i = 1; i <= s.size(); i++) {
            for(int j = 1; j <= p.size(); j++) {
                if(p[j - 1] != '*') {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }else {
                    /**最容易搞錯的地方**/
                    dp[i][j] = j > 1 && dp[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};