class Solution {
private:
    vector<int> father;
    int count;
    int find(int x) {
        if(father[x] == x)
            return x;
        return father[x] = find(father[x]);
    }
    void connect(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if(fx != fy) {
            father[fx] = fy;
            count--;
        }
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.size() == 0)
            return 0;
        int n = M.size();
        count = n;
        father.resize(n);
        for(int i = 0; i < n; i++)
            father[i] = i;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(M[i][j] == 1) {
                    connect(i, j);
                }
            }
        }
        
        return count;
    }
};