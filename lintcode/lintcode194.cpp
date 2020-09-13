// 用雙指針，一根指針指向string目前遍歷到的char
// 第二根指針指向dict中每一個單詞
// 只要match到指針都會向後移一位
// 最後再檢查每一個第二根指針是不是都全部match到了
vector<string> findWords(string &str, vector<string> &dict) {
    vector<string> res;
    // track the current checked idx of word
    vector<int> track(dict.size(), 0);
    for(int i = 0; i < str.size(); i++) {
        for(int j = 0; j < dict.size(); j++) {
            if(track[j] == -1)
                continue;   // already matched
            if(str[i] == dict[j][track[j]])
                track[j]++;     // match one char
            
            if(track[j] == dict[j].size())
                track[j] = -1;  // finish matched
        }
    }
    for(int i = 0; i < dict.size(); i++) {
        if(track[i] == -1)
            res.push_back(dict[i]);
    }
    return res;
}
// 這題還好限制了string長度10^5和字典總單字長度10^3
// 照上面最差也10^8，算是勉勉強強
// 但是想像下，如果我們在查詢dict中的字時都能馬上找到下一個字來跳轉，是不是能省掉很多麻煩呢？
// 所以我們這邊做個strmap來完成這個功能
// strmap[i][j]代表i之後最近的字母j在何處 （這邊因為只有小英文字母，所以我創造26大小的空間
// 思路也很妙：想像一下如果一個字串 rlab
// 我們知道 strmap[l][l] = 1, strmap[l][a] = 2, strmap[l][b]
// 我們要得知 strmap[r]的資料就很簡單了，只需要加上 strmap[r][r] = 0，其他就都跟strmap[l]都一樣
vector<string> findWords(string &str, vector<string> &dict) {
    if(str.length() == 0 || dict.size() == 0) return vector<string>({});
    vector<vector<int>> strmap(str.size());
    strmap[str.size() - 1].assign(26, -1);
    for(int i = str.size() - 1; i >= 0; i--) {
        if(i == str.size() - 1) {
            strmap[i][str[i] - 'a'] = i;
        } else {
            strmap[i] = strmap[i + 1];
            strmap[i][str[i] - 'a'] = i;
        }
    }
    vector<string> res;
    for(int i = 0; i < dict.size(); i++) {
        int cur_idx = 0;
        for(int j = 0; j < dict[i].size(); j++){
            if(strmap[cur_idx][dict[i][j] - 'a'] == -1) break;
            cur_idx = strmap[cur_idx][dict[i][j] - 'a'];
            if(j == dict[i].size() - 1) res.push_back(dict[i]);
        }
    }
    return res;
}