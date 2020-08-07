#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define F first
#define S second
#define mp make_pair
using namespace std;
typedef pair<int, int> pp;

struct cmp {
	bool operator()(pp a, pp b) {
		if(a.first == b.first) return a.second < b.second;    // descending with second
		return a.first > b.first;       // ascending with first
	}
};

int main() { _
    int l, h, r, prevh;
    multiset<int> s;
    s.insert(0);
    priority_queue<pp, vector<pp>, cmp> pq;
    while(cin >> l >> h >> r) {
    	pq.push(mp(l, h));
        pq.push(mp(r, h * -1));
    }
    prevh = 0;
    while(!pq.empty()) {
    	auto hd = pq.top();
    	pq.pop();
    	if(hd.S > 0)
    		s.insert(hd.S);
    	else
    		s.erase(s.find(hd.S * -1));
    	if(pq.empty())
    		cout << hd.F << " 0" << '\n';
		else if(*(--s.end()) != prevh) {
			cout << hd.F << ' ' << *(--s.end()) << ' ';
			prevh = *(--s.end());
		}
	}
    return 0;
}
