// beats over 100% of submission
class Solution {
private:
    void dfs(int n, int row, int col, int pie, int na){
        // 1 means available
        int available = ((1 << n) - 1) & ~(col | pie | na);  // get only lower n bits
        while(available != 0){    // if there is still available seat
            int p = available & -available;     // pick the rightmost seat
            available ^= p;      // reverse the bit
            
            if(row == n - 1){    // the last row
                count++;
                return;
            }else{
                // col ^ p, pie ^ p, na ^ p: reverse the pth bit
                // pie: shift right 1 bit each time switch to the next row
                // na: shift left 1 bit each time switch to the next row
                dfs(n, row+1, col ^ p, (pie ^ p) >> 1, (na ^ p) << 1);
            }
        }
    }
public:
    int count;
    int totalNQueens(int n) {
        if(n <= 0) return 1;
        
        count = 0;
        int col = 0;
        int pie = 0;
        int na = 0;
        
        dfs(n, 0, col, pie, na);
        
        return count;
    }
};