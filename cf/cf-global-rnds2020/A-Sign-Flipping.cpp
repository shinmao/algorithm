#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr.at(i);
    }
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        if (arr.at(i) > 0) arr.at(i) = -arr.at(i);
      } else {
        if (arr.at(i) < 0) arr.at(i) = -arr.at(i);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (i > 0) {
        cout << " ";
      }
      cout << arr.at(i);
    }
    cout << '\n';
  }
  return 0;
}