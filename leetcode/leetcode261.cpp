// 這裡用連通塊來確定樹是否合法
class Solution {
private:
    vector<int> father;
    int count;
    int find(int x) {
        if(father[x] == x)
            return x;
        // path compression
        return father[x] = find(father[x]);
    }
    // ***important part***
    // connect each nodes and check number of connected part
    void connect(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if(fx != fy) {
            father[fx] = fy;
            count--;
        }
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int num = edges.size();
        if(num != n - 1)
            return false;
        count = n;
        father.resize(n);
        // init
        for(int i = 0; i < n; i++)
            father[i] = i;
        for(int i = 0; i < num; i++)
            connect(edges[i][0], edges[i][1]);
        
        return count == 1;
    }
};