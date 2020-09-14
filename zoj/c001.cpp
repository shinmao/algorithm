#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() { _
	string a, b;
	while(cin >> a >> b) {
		vector<vector<int> > dp(a.length(), vector<int>(b.length(), 0));
		// boundary
		dp[0][0] = (a[0] == b[0] ? 1 : 0);
		int tmp = 0;
		for(int i = 0; i < a.length(); i++) {
			if(a[i] == b[0])
				tmp = 1;
			dp[i][0] = tmp;
		}
		tmp = 0;
		for(int j = 0; j < b.length(); j++) {
			if(b[j] == a[0])
				tmp = 1;
			dp[0][j] = tmp;
		}
		for(int i = 1; i < a.length(); i++) {
			for(int j = 1; j < b.length(); j++) {
				if(a[i] == b[j])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
		cout << dp[a.length() - 1][b.length() - 1] << '\n';
	}
	return 0;
}
