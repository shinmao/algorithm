#include <stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() { _
    int N, tmp;
    vector<int> in_train;
    deque<int> out_train;
    while(cin >> N and N) {
        while(true) {
            in_train.clear();
            out_train.clear();
            cin >> tmp;
            if(tmp == 0) break;
            out_train.push_back(tmp);
            for(int i = 1; i < N; ++i) {
                cin >> tmp;
                out_train.push_back(tmp);
            }
            for(int i = 1; i <= N; ++i) {
                in_train.push_back(i);
                while(!in_train.empty() and in_train.back() == out_train.front()) {
                    in_train.pop_back();
                    out_train.pop_front();
                }
            }
            cout << (in_train.empty() ? "Yes" : "No") << '\n';
        }
        cout << '\n';
    }
    return 0;
}