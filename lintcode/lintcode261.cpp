// https://www.jiuzhang.com/problem/maximum-connected-area/#tag-lang-ALL
// https://blog.1pwnch.com/posts/lintcode-maximum-conn-area/
class Solution {
private:
    vector<int> father;
    vector<int> area_;
    int not_zero = 0;
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
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
            area_[fy] += area_[fx];
        }
    }
public:
    inline int hash(int i, int j, int m) { return i*m + j; }
    
    bool isValid(vector<vector<int>> &m, int i, int j) {
        if(i < 0 || j < 0 || i >= m.size() || j >= m[0].size())
            return false;
        if(m[i][j] == 0)
            return false;
        return true;
    }

    int maxArea(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int area = 0;
        father.resize(n*m);
        area_.resize(n*m);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 1) {
                    not_zero++;
                    father[hash(i, j, m)] = hash(i, j, m);
                    area_[hash(i, j, m)] = 1;
                }
            }
        }
        
        if(not_zero == n*m)
            return not_zero;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 1) {
                    for(auto d : dir) {
                        int nxtx = i + d[0];
                        int nxty = j + d[1];
                        if(isValid(matrix, nxtx, nxty))
                            connect(hash(i, j, m), hash(nxtx, nxty, m));
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    int a = 1;
                    vector<bool> visited(n*m, false);
                    for(auto d : dir) {
                        int nxtx = i + d[0];
                        int nxty = j + d[1];
                        if(isValid(matrix, nxtx, nxty)) {
                            int f = find(hash(nxtx, nxty, m));
                            if(!visited[f]) {
                                visited[f] = true;
                                a += area_[f];
                            }
                        }
                    }
                    area = max(area, a);
                }
            }
        }
        
        return area;
    }
};