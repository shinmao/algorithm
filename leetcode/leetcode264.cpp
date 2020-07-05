// brute force
// idea: generate all ugly number and sort
// trible loops -> 2^k1 * 3^k2 * 5^k3
// O(nlogn) - beats over 20% of submission - 288ms
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly;
        for(long a = 1; a <= INT_MAX; a*=2)
            for(long b = a; b <= INT_MAX; b*=3)
                for(long c = b; c <= INT_MAX; c*=5)
                    ugly.push_back(c);

        sort(ugly.begin(), ugly.end());
        
        return ugly.at(n-1);
    }
};

// testcase 會多次調用這個function
// 可是其實我們用第一次的arr回傳結果就可以了
// 所以將 ungly聲明為 static -> 大就不會多次初始化
// 下面loop也不會再進去了
// O(nlogn) - beats over 100% of submission - 0ms
// beats over 89% of submission on space complexity
class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> ugly;
        if(nums.empty()){
            // xxx

            sort(ugly.begin(), ugly.end());
        }
        
        return ugly.at(n-1);
    }
};

// 有一個比較hack的方法
// 因為最大就到1690
// 所以提前去生成所有的醜數
// 然後直接查詢 - O(n)

// this solution is what this problem wants to test
// idea: each ugly number is 
// {latest processed ugly num * 2  or  
// latest processed ugly num * 3  or  
// latest processed ugly num * 5}
class Solution {
public:
    int nthUglyNumber(int n) {
        static vector <int> results (1,1);
        static int i2 = 0, i3 = 0, i5 = 0;
        while (results.size() < n)
        {
            results.push_back(min(results[i2] * 2, min(results[i3] * 3, results[i5] * 5)));
            if (results.back() == results[i2] * 2) ++i2;
            if (results.back() == results[i3] * 3) ++i3;
            if (results.back() == results[i5] * 5) ++i5;
        }
        return results.back();
    }
};