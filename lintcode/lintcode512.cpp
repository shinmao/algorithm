class Solution {
public:
    int numDecodings(string &s) {
        // use stoi() to convert string to integer
        // [1 - 26] in dictionary
        int n = s.length();
        if(n == 0 || s == "0")
            return 0;
        
        // dp[i]: ways of first i elements
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            // 因為字母編碼後頂多佔兩位
            if(s[i - 1] != '0')
                dp[i] += dp[i - 1];
                
            if(s[i - 2] != '0' && stoi(s.substr(i - 2, 2)) <= 26) {
                // the word >= 10 and <= 26
                dp[i] += dp[i - 2];
            }
            
            if(!dp[i])
                return 0;
        }
        
        return dp[n];
    }
};