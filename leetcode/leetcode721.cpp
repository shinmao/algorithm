// 標準找父親模板
int find(vector<int>& union_fnd, int x) {
    while(union_fnd[x] != x)
        x = union_fnd[x];
    return x;
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    // name_id father: 注意這邊的father是root，會追溯到最上面
    vector<int> union_fnd(accounts.size());
    // mail指向name_id：這樣我們就可以用mail union account了
    unordered_map<string, int> m;
    // 中間做個小整合
    unordered_map<int, vector<string>> res_map;

    for (int i = 0; i < accounts.size(); ++i) {
        union_fnd[i] = i; // 先初始化成自己
        for(int j = 1; j < accounts[i].size(); ++j) {
            if(!m.count(accounts[i][j])) {   // 如果沒人用過這個mail
                m[accounts[i][j]] = union_fnd[i];   // 那代表這個mail的name_id勢必是自己
            }else {
                // 有人用過這個mail
                // 那我的root的root肯定也跟這人有關係
                union_fnd[find(union_fnd, i)] = find(union_fnd, m[accounts[i][j]]);
            }
        }
    }

    for(auto it : m) {
        int x = find(union_fnd, it.second);
        res_map[x].push_back(it.first);
    }

    vector<vector<string>> res;
    for(auto it : res_map) {
        vector<string> mail = it.second;
        sort(mail.begin(), mail.end());
        mail.insert(mail.begin(), accounts[it.first][0]);
        res.push_back(mail);
    }
    return res;
}