// idea:
// 記錄在string的每一個index時，<a, c, g, t>各出現了幾次
// 拿Q's index時的次數去減掉P's index時的次數會得到兩個之間各個字母出現幾次
// 不過要注意：直接相減會連P's index本身上面這個字母的次數一起減掉
// 我因為這樣吃了好幾次WA
// O(N + M)
// ref: https://app.codility.com/demo/results/trainingSUQEDA-SEN/
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    map<char, int> mp;
    mp.insert(make_pair('A', 1));
    mp.insert(make_pair('C', 2));
    mp.insert(make_pair('G', 3));
    mp.insert(make_pair('T', 4));
    vector<vector<int> > acgt(4, vector<int>(1, 0));
    // a: c: g: t:
    int count[4] = {0, 0, 0, 0};
    for(int i = 0; i < S.length(); i++) {
        switch(mp[S[i]]) {
            case 1:
                count[0] += 1;
                break;
            case 2:
                count[1] += 1;
                break;
            case 3:
                count[2] += 1;
                break;
            case 4:
                count[3] += 1;
                break;
        }
        for(int j = 0; j < 4; j++) {
            acgt[j].push_back(count[j]);
        }
    }
    vector<int> res;
    for(int i = 0; i < P.size(); i++) {
        if(P[i] == Q[i]) {
            int idx = Q[i];
            res.push_back(mp[S[idx]]);
            continue;
        }
        for(int j = 0; j < 4; j++) {
            if(acgt[j][Q[i] + 1] - acgt[j][P[i] + 1] > 0) {
                int idx = P[i];
                if(mp[S[idx]] < j + 1) 
                    res.push_back(mp[S[idx]]);
                else
                    res.push_back(j+1);
                break;
            }
        }
    }
    return res;
}
