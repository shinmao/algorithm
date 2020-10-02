long long kDistinctCharacters(string &s, int k) {
    long long n = s.size();
    if(n == 0)
        return 0;
    
    // 這邊也可以換成<int, int>
    // 或甚至是vector<int> v(26, 0)
    unordered_map<char, int> dict;
    long long distinct = 0;
    long long cnt = 0;
    long long left = 0, right = 0;
    while(right < n) {
        if(dict[s[right]] == 0)
            distinct++;
        dict[s[right]]++;
        right++;
        // 前面數組一直延伸直到符合條件
        // 開始試試看後面的子數組是否也能符合條件
        while(left <= right && distinct >= k) {
            cnt += n - right + 1;
            dict[s[left]]--;
            if(dict[s[left]] == 0)
                distinct--;
            left++;
        }
    }
    
    return cnt;
}