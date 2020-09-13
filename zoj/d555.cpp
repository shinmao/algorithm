#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);
using namespace std;

struct Point {
	int x, y;
};

struct cmp {
	bool operator()(Point a, Point b) {
		if(a.x != b.x) return a.x < b.x;  // decreasing with x
		return a.y < b.y;  // decreasing with y
	}
};

int main() { _
	int n;
	int t = 0;
	while(cin >> n) {
		cout << "Case " << ++t << ':' << '\n';
		vector<Point> v(n);
		vector<Point> res(n);
		for(int i = 0; i < n; i++) {
			cin >> v[i].x >> v[i].y;
		}
		sort(v.begin(), v.end(), cmp());
		int cnt = 0, maxy = INT_MIN;
		for(int i = n - 1; i >= 0; i--) {
			if(v[i].y > maxy) {
				res[cnt].x = v[i].x;
				res[cnt].y = v[i].y;
				cnt++;
				maxy = v[i].y;
			}
		}
		cout << "Dominate Point: " << cnt << '\n';
		for(int i = cnt - 1; i >= 0; i--) {
			cout << '(' << res[i].x << ',' << res[i].y << ')' << '\n';
		}
	}
	return 0;
}