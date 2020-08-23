// idea:
// 這題考得binary search的觀念很難聯想到
// 主要是應用在K上
// 我們可以先透過指定一個sum來用get_blocks算出相對應的block數
// 若是block數大於K，代表我們指定的sum太小了，我們必須把指定的sum調高
// 若是block數小於K  代表我們指定的sum太大了  我們必須把指定的sum調低
// time complexity: O(N*log(N+M))
#include <bits/stdc++.h>
using namespace std;

int get_blocks(int mid_sum, vector<int> &A) {
    int blocks = 0, sum = 0;
    for(auto& i : A) {
        sum += i;
        if(sum > mid_sum) {
            sum = i;
            blocks += 1;
        }
    }
    return blocks + 1;
}

int solution(int K, int M, vector<int> &A) {
    int sum = 0;
    int max = 0;
    for(auto& i : A) {
        if(i > max) max = i;
        sum += i;
    }
    if(K == 1) {
        return sum;
    }else {
        if(K >= A.size()) 
            return max;
        else {
            while(max <= sum) {
                int mid_sum = max + ((sum - max) >> 1);
                int count = get_blocks(mid_sum, A);
                if(count > K)
                    max = mid_sum + 1;
                else
                    sum = mid_sum - 1;
            }
        }
    }
    return max;
}
