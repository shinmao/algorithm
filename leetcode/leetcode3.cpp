// 沒有用unordered真的差很多喔！
// 但是用vector還是稍微比較快
// 因為 set 還是有可能會有線性的插入時間
int lengthOfLongestSubstring(string s) {
    int len = s.size(), res = 0;
    if(len == 0) return 0;
    unordered_set<char> dict;
    int left = 0, right = 1;
    while(left < len) {
        while(left < right && right <= len && dict.count(s[right - 1]) == 0) {
            dict.insert(s[right - 1]);
            res = max(res, right - left);
            right++;
        }
        dict.erase(s[left]);
        left++;
    }
    return res;
}