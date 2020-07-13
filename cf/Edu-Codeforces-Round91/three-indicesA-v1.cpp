// 31ms
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
 
using namespace std;
 
int main() { _
	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i = 0; i < n; ++i) cin >> arr[i];
		int start = -1;
		for(int i = 1; i < n-1; ++i) {
			if(arr[i] > arr[i-1] and arr[i+1] < arr[i]) {
			    start = i-1;
			    break;
			}
		}
		if(start == -1) 
			cout << "NO" << '\n';
		else {
			start++;
			cout << "YES" << '\n';
			cout << start << " " << start + 1 << " " << start + 2;
			cout << '\n';
		}
	}
 
	return 0;
}