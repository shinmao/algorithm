class Solution {
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    vector<string> dfs(string &s, 
                unordered_map<string, vector<string>> &memo, 
                unordered_set<string> &wordDict) {
        if(memo.count(s) != 0)
            return memo[s];
        
        vector<string> res;
        
        if(s.length() == 0)
            return res;
        
        // s本身是否就是單字
        if(wordDict.count(s) != 0)
            res.push_back(s);
        
        // 把s分解成單字
        for(int len = 1; len < s.length(); ++len) {
            string word = s.substr(0, len);
            if(wordDict.count(word) == 0)
                continue;
                
            string suffix = s.substr(len);
            vector<string> res_ = dfs(suffix, memo, wordDict);
            for(auto i : res_) {
                res.push_back(word + " " + i);
            }
        }
        
        memo[s] = res;
        return res;
    }
    
    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
        // write your code here
        if(wordDict.size() == 0 || s.length() == 0)
            return {};
        
        vector<string> res;
        // memo在word中有相同的單字時特別好用
        unordered_map<string, vector<string>> memo;
        res = dfs(s, memo, wordDict);
        
        return res;
    }
};