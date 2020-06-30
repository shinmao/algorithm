// most important idea in validate
// whether two queens are on the same slash or not
// the absolute distance between two columns is same to two rows or not
// beats over 55.13% of submission
class Solution {
    private:
        vector<int> sublist;
        vector<vector<string>> result;
        decltype(auto) construct(vector<int>& sublist){
            vector<string> result;
            for(auto i = sublist.begin(); i != sublist.end(); i++){
                string str = "";
                for(int j = 0; j < sublist.size(); j++){
                    str += (j == *i ? "Q" : ".");
                }
                result.push_back(str);
            }
            return result;
        }
        decltype(auto) validate(vector<int>& sublist, int col){
            int row = sublist.size();
            for(int i = 0; i < row; i++){
                if(col == sublist.at(i)) return false;
                if(abs(row - i) == abs(col - sublist.at(i))) return false;
            }
            return true;
        }
        void dfs(int n, vector<int>& sublist, vector<vector<string>>& result){
            if(sublist.size() == n){
                result.push_back(construct(sublist));
                return;
            }
            for(int i = 0; i < n; i++){
                if(!validate(sublist, i)) continue;
                sublist.push_back(i);
                dfs(n, sublist, result);
                sublist.pop_back();
            }
        }
    public:
        vector<vector<string>> solveNQueens(int n) {
            if(n <= 0){
                vector<string> s;
                result.push_back(s);
                return result;
            }
            
            dfs(n, sublist, result);
            
            return result;
        }
    };
}

// idea: col[position], pie[position], na[position]
// we don't need to validate all the back rows each time place a queen on the new row!
// beats over 32% of submission
class Solution {
private:
    vector<int> sublist;
    vector<vector<string>> result;
    decltype(auto) construct(vector<int>& sublist){
        vector<string> result;
        for(auto i = sublist.begin(); i != sublist.end(); i++){
            string str = "";
            for(int j = 0; j < sublist.size(); j++){
                str += (j == *i ? "Q" : ".");
            }
            result.push_back(str);
        }
        return result;
    }
    void dfs(int n, 
             int row, 
             vector<bool>& col, 
             vector<bool>& pie, 
             vector<bool>& na, 
             vector<int>& sublist, 
             vector<vector<string>>& result){
        
        if(row >= n){
            result.reserve(result.size() + 1);
            result.push_back(construct(sublist));
            return;
        }
        for(int pos = 0; pos != n; pos++){
            int i = row + pos;
            int j = n - 1 + pos - row;
            if(col.at(pos) == true || pie.at(i) == true || na.at(j) == true) continue;
            
            col.at(pos) = true;
            pie.at(i) = true;
            na.at(j) = true;
            sublist.push_back(pos);
            
            dfs(n, row+1, col, pie, na, sublist, result);
            
            col.at(pos) = false;
            pie.at(i) = false;
            na.at(j) = false;
            sublist.pop_back();
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n <= 0){
            vector<string> s;
            result.push_back(s);
            return result;
        }
        
        vector<bool> col(n);
        vector<bool> pie(2*n - 1);
        vector<bool> na(2*n - 1);
        
        dfs(n, 0, col, pie, na, sublist, result);
        
        return result;
    }
};

// idea: change boolean array to bit array
// beats over 100% of submission
class Solution {
private:
    void dfs(int n, 
             int row, 
             int col, 
             int pie, 
             int na, 
             vector<string>& sublist, 
             vector<vector<string>>& result){
        
        if(row >= n){
            result.push_back(sublist);
            return;
        }
        
        for(int pos = 0; pos < n; pos++){
            int i = row + pos;
            int j = n - 1 + pos - row;
            // 0 means seat is still available
            // if the seat is 1, it means the seat is already be taken
            if((((col >> pos) | (pie >> i) | (na >> j)) & 1) != 0) continue;
            col ^= (1 << pos);    // reverse the bit
            pie ^= (1 << i);
            na ^= (1 << j);
            sublist.at(row).at(pos) = 'Q';
            dfs(n, row+1, col, pie, na, sublist, result);
            col ^= (1 << pos);
            pie ^= (1 << i);
            na ^= (1 << j);
            sublist.at(row).at(pos) = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> sublist(n, string(n, '.'));
        vector<vector<string>> result;
        if(n <= 0){
            vector<string> s;
            result.push_back(s);
            return result;
        }
        
        int col = 0;
        int pie = 0;
        int na = 0;
        
        dfs(n, 0, col, pie, na, sublist, result);
        
        return result;
    }
};

// idea: 請參考leetcode 52
// beats over 83% of submission
class Solution {
    private:
        vector<int> sublist;
        vector<vector<string>> result;
        decltype(auto) construct(vector<int>& sublist){
            vector<string> subresult;
            for(auto i = sublist.begin(); i != sublist.end(); i++){
                string str = "";
                for(int j = 0; j < sublist.size(); j++){
                    if(j == *i){
                        str += "Q";
                    }else{
                        str += ".";
                    }
                }
                subresult.push_back(str);
            }
            return subresult;
        }
        void dfs(int n, 
                 int row, 
                 int col, 
                 int pie, 
                 int na, 
                 vector<int>& sublist, 
                 vector<vector<string>>& result){
            
            int available = ((1 << n) - 1) & ~(col | pie | na);
            while(available != 0){
                int p = available & -available;
                available ^= p;
                
                int col_indexQ = (n-1) - log2(p);
                sublist.push_back(col_indexQ);
                
                if(row == n-1){
                    result.push_back(construct(sublist));
                    sublist.pop_back();
                    return;
                }else{
                    dfs(n, row+1, (col ^ p), (pie ^ p) >> 1, (na ^ p) << 1, sublist, result);
                    sublist.pop_back();
                }
            }
        }
    public:
        vector<vector<string>> solveNQueens(int n) {
            if(n <= 0){
                vector<string> s;
                result.push_back(s);
                return result;
            }
            
            int col = 0;
            int pie = 0;
            int na = 0;
            
            dfs(n, 0, col, pie, na, sublist, result);
            
            return result;
        }
    };
}

// 以為上面的解法最強了嗎？
// 還沒！善用C++的黑魔法 template
// 我拿到了 beats over 99% of submission
// 下面的版本跟上面就只差在將construct改成template
template <typename T>
    decltype(auto) construct(T& sublist){
        vector<string> subresult;
        for(auto i = sublist.begin(); i != sublist.end(); i++){
            string str = "";
            for(int j = 0; j < sublist.size(); j++){
                if(j == *i){
                    str += "Q";
                }else{
                    str += ".";
                }
            }
            subresult.push_back(str);
        }
        return subresult;
    }
}

// 從discussion board上又學到了一種更簡潔的寫法
// idea: 只要善用sublist，根本不需要construct
// same beats over 99% of submission
class Solution {
private:
    void dfs(int n, 
             int row, 
             int col, 
             int pie, 
             int na, 
             vector<string>& sublist, 
             vector<vector<string>>& result){
        
        int available = ((1 << n) - 1) & ~(col | pie | na);
        while(available != 0){
            int p = available & -available;
            available ^= p;
            
            int col_indexQ = (n-1) - log2(p);
            sublist.at(row).at(col_indexQ) = 'Q';
            
            if(row == n-1){
                result.push_back(sublist);
                sublist.at(row).at(col_indexQ) = '.';
                return;
            }else{
                dfs(n, row+1, (col ^ p), (pie ^ p) >> 1, (na ^ p) << 1, sublist, result);
                sublist.at(row).at(col_indexQ) = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> sublist(n, string(n, '.'));
        vector<vector<string>> result;
        if(n <= 0){
            vector<string> s;
            result.push_back(s);
            return result;
        }
        
        int col = 0;
        int pie = 0;
        int na = 0;
        
        dfs(n, 0, col, pie, na, sublist, result);
        
        return result;
    }
};