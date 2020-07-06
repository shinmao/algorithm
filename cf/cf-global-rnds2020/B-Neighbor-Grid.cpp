// 62ms
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        int row;
        int col;
        bool ok = true;
        cin >> row >> col;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                int grid = 0;
                if(((i == 0) or (i == row-1)) and ((j == 0) or (j == col-1))){
                    grid += 2;
                }else if(((i == 0) or (i == row-1)) or ((j == 0) or (j == col-1))){
                    grid += 3;
                }else{
                    grid += 4;
                }
                int x;
                cin >> x;
                if(x > grid) ok = false;
            }
        }
        if(ok == false){
            cout << "NO" << '\n';
        }else{
            cout << "YES" << '\n';
            for(int i = 0; i < row; ++i){
                for(int j = 0; j < col; ++j){
                    if(j > 0) cout << " ";
                    int grid = 0;
                    if(((i == 0) or (i == row-1)) and ((j == 0) or (j == col-1))){
                        grid += 2;
                    }else if(((i == 0) or (i == row-1)) or ((j == 0) or (j == col-1))){
                        grid += 3;
                    }else{
                        grid += 4;
                    }
                    cout << grid;
                }
                cout << '\n';
            }
        }
    }
 
    return 0;
}