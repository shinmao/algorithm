class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        if(m == 0 || A.size() == 0)
            return 0;
            
        /**
         * condition: capacity, available items
         * choice: put or not put
         * dp[i][j]: the biggest size can be filled with first i items with size j
         * if not put ith item:
         * dp[i][j] = dp[i - 1][j]
         * if put ith item:
         * dp[i][j] = dp[i - 1][j - A[i]] + A[i]
         */
        vector<vector<int>> dp(A.size() + 1, vector<int>(m + 1, 0));
        
        for(int i = 0; i <= A.size(); i++) {
            // if capacity == 0
            dp[i][0] = 0;
        }
        
        for(int j = 0; j <= m; j++) {
            // if not put any items
            dp[0][j] = 0;
        }
        
        for(int i = 1; i <= A.size(); i++) {
            for(int j = 1; j <= m; j++) {
                if(j >= A[i - 1])
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i - 1]] + A[i - 1]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        
        return dp[A.size()][m];
    }
};

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        if(m == 0 || A.size() == 0)
            return 0;
        
        int n = A.size();
        /**
         * if not put ith item:
         * dp[i][lb] = dp[i - 1][lb]
         * if put ith item:
         * dp[i][lb] = dp[i - 1][lb - A[i]] + A[i]
         * dp[i] 只跟 dp[i - 1] 有關
         * 優化成 dp[lb] = dp[lb - A[i]] + A[i]
         */
        vector<int> dp(m + 1, 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = m; j >= A[i]; j--) {
                dp[j] = max(dp[j], dp[j - A[i]] + A[i]);
            }
        }
        
        return dp[m];
    }
};