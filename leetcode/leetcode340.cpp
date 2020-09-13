// 這題剛開始有點太堅持要使用一個變數完成所有功能呢
// 這邊 count是為了方便，我們總不可能每次都把整個dict掃一遍去check有沒有k吧
// dict是為了記各個單詞的數量，當有多個同樣字母減少一個時，種類是不會變的
// 這題需要注意的點是我們while迴圈允許 <= k的狀況在運行
// 可是等於k的情況下我們就要分兩種狀況: 新加進去的單字，會不會增加k呢？
// 所以 dict[s[right]] == 0 那行就是在判斷：如果等於k時我們又加入一個新單字，當然就爆了
int lengthOfLongestSubstringKDistinct(string s, int k) {
    if(s.size() == 0 || k == 0) return 0;
    int maxLength = 0, count = 0;
    int left = 0, right = 0;
    vector<int> dict(256, 0);
    while(left < s.size() && left <= right) {
        while(right < s.size() && count <= k) {
            if(dict[s[right]] == 0) {
                if(count == k) break;
                count++;
            }
            dict[s[right]]++;
            right++;
        }
        maxLength = max(maxLength, right - left);
        dict[s[left]]--;
        if(dict[s[left]] == 0) count--;
        left++;
    }
    return maxLength;
}