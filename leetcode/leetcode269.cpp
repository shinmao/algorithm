// 簡而言之就是topology sort
// 但是我在寫的時候手滑犯了超多錯誤
class Solution {
public:
    unordered_map<char, unordered_set<char>> neighbor;
    unordered_map<char, int> in_degree;
    
    bool findNeighbor(string a, string b) {
        // description of problem is ambiguous
        // 題目規定第二個字不能是第一個字的前綴
        int astart = 0, bstart = 0;
        while(astart < a.length() && bstart < b.length() && a[astart] == b[bstart]) {
            astart++;
            bstart++;
        }
        if(astart < a.length() && bstart == b.length())
            return false;   // invalid
        if(astart < a.length() && bstart < b.length()) {
            if(!neighbor[a[astart]].count(b[bstart])) {
                // 這邊我一開始都沒判定會不會加入重複的edge
                // 導致我的in_degree加太多
                // 這樣會讓node加不進queue裡喔...
                neighbor[a[astart]].insert(b[bstart]);
                in_degree[b[bstart]]++;
            }
        }
        return true;
    }
    
    string alienOrder(vector<string>& words) {
        if(words.size() == 0)
            return "";
        
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].size(); j++) {
                in_degree[words[i][j]] = 0;
            }
        }
        
        for(int i = 0; i < words.size() - 1; i++) {
            if(!findNeighbor(words[i], words[i + 1]))
                return "";
        }
        
        queue<char> q;
        // add whose in-degree = 0 as root
        for(auto it : in_degree) {
            if(it.second == 0)
                q.push(it.first);
        }
        
        string res = "";
        while(!q.empty()) {
            char head = q.front();
            q.pop();
            res.push_back(head);
            for(auto it : in_degree) {
                cout << it.first << ' ' << it.second << '\n';
            }
            for(char it : neighbor[head]) {
                in_degree[it]--;
                if(in_degree[it] == 0)
                    q.push(it);
            }
        }
        // 這個可以用來判斷cycle的存在
        if(res.length() != in_degree.size())
            return "";
        
        return res;
    }
};