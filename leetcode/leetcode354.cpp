/**
 * 這道題目大概也會想到LIS
 * 只不過要同時寬度和高度作LIS不知道怎麼做
 * 思維：
 * 讓envelopes先按照w升序
 * 但要注意的是，若w相同，兩個envelopes將不能夠互相包含
 * 為了限制從寬度相同的envelopes中只能選一個
 * 在w相同時，讓h倒序就好
 * 接下來就用h數組作LIS就好
 * 這裡一樣用patience sorting
 */
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n == 0)
            return 0;
        
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> h(n);
        for(int i = 0; i < n; i++)
            h[i] = envelopes[i][1];
        vector<int> top;
        for(int i = 0; i < n; i++) {
            int card = h[i];
            int l = 0, r = top.size();
            while(l < r) {
                int m = l + (r - l)/2;
                if(top[m] > card) {
                    r = m;
                }else if(top[m] < card) {
                    l = m + 1;
                }else{
                    r = m;
                }
            }
            if(l == top.size())
                top.push_back(card);
            else
                top[l] = card;
        }
        
        return top.size();
    }
};