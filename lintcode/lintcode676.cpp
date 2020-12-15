class Solution {
public:
    int numDecodings(string &s) {
        // '*' represent for 1 - 9
        int n = s.length();
        int mod = 1e9 + 7;
        if(n == 0 || s[0] == '0')
            return 0;
            
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = (s[0] == '*') ? 9 : 1;
            
        for(int i = 2; i <= n; ++i) {
            if( s[i - 1] == '0' ) {
                if( s[i - 2] == '1' || s[i - 2] == '2' ) {
                    dp[i] += dp[i - 2];
                }else if( s[i - 2] == '*' ) {
                    dp[i] += 2 * dp[i - 2];
                }else {
                    return 0;
                }
            }else if( s[i - 1] >= '1' && s[i - 1] <= '9' ) {
                // for one digit
                dp[i] += dp[i - 1];
                // for two digit
                if( s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6') ) {
                    dp[i] += dp[i - 2];
                }else if( s[i - 2] == '*' ) {
                    dp[i] += ( s[i - 1] <= '6' ) ? (2 * dp[i - 2]) : dp[i - 2];
                }
            }else {
                // s[i - 1] == '*'
                // for one digit
                dp[i] += 9 * dp[i - 1];
                // for two digit
                if(s[i - 2] == '1') {
                    // 11 - 19
                    dp[i] += 9 * dp[i - 2];
                }else if(s[i - 2] == '2') {
                    // 21 - 26
                    dp[i] += 6 * dp[i - 2];
                }else if (s[i - 2] == '*'){
                    dp[i] += 15 * dp[i - 2];
                }
            }
            
            dp[i] %= mod;
        }
        
        return dp[n];
    }
};