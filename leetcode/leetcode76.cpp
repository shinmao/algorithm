// 做兩張map，先把t的map做起來，然後在遍歷s的時候去比對t-map
// 另外有兩個變數 smatched / tmatched
// smatched代表 s中已經符合t-map要求的個數，tmatched則是總要求數
string minWindow(string s, string t) {
    if(t.size() == 0) return "";
    vector<int> target(256, 0);
    vector<int> source(256, 0);
    int smatched = 0, tmatched = 0;
    for(int i = 0; i < t.size(); i++) {
        if(target[t[i]] == 0) tmatched++;
        target[t[i]]++;
    }
    int left = 0, right = 0, n = s.size(), len = INT_MAX, start = 0;
    while(left < n && left <= right) {
        while(right < n && smatched < tmatched) {  // 這邊因為 = 就一定是結束的情況，所以不再列入while條件
            source[s[right]]++;
            if(source[s[right]] == target[s[right]])  // 有一個單字已經符合要求了
                smatched++;
            right++;
        }
        // 從while迴圈出來的未必是已經match完畢的，所以再加一層if判斷
        if(smatched == tmatched && (right - left) < len) {  // 如果符合條件，看看是不是比較短
            len = right - left;
            start = left;  // 最後打算用substr，所以這裡就順便把字串起始點記錄下來
        }
        if(source[s[left]] == target[s[left]])  // 如果拿掉的字屬於t-map裡面已經match成功的，我們必須減少一個match數
            smatched--;
        source[s[left]]--;
        left++;
    }
    if(len == INT_MAX) return "";
    return s.substr(start, len);
}