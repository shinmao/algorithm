#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main() { _
	int tc;
	cin >> tc;
	while(tc--) {
		string s;
		cin >> s;
		vector<char> input(s.begin(), s.end());
		vector<int> count(3, 0);  // S, R, P
		for(auto i = input.begin(); i != input.end(); ++i) {
			if(*i == 'S')
				count[0]++;
			else if(*i == 'R')
				count[1]++;
			else if(*i == 'P')
				count[2]++;
		}

		int m = max(count[0], max(count[1], count[2]));
		if(count[0] == m)
			for(int i = 0; i < input.size(); ++i) cout << 'R';
		else if(count[1] == m)
			for(int i = 0; i < input.size(); ++i) cout << 'P';
		else if(count[2] == m)
			for(int i = 0; i < input.size(); ++i) cout << 'S';
		cout << '\n';
	}
	
    	return 0;
}