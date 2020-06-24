// most important idea in validate
// whether two queens are on the same slash or not
// the absolute distance between two columns is same to two rows or not
// beats over 23% of submission
class Solution {
    private List<String> construct(List<Integer> sublist){
        List<String> result = new ArrayList<>();
        int size = sublist.size();
        for(int i = 0; i < size; i++){
            String str = "";
            for(int j = 0; j < size; j++){
                str += (j == sublist.get(i) ? "Q" : ".");
            }
            result.add(str);
        }
        return result;
    }
    
    private boolean validate(List<Integer> sublist, int col){
        int row = sublist.size();
        for(int i = 0; i < row; i++){
            if(col == sublist.get(i)) return false;
            if(Math.abs(row - i) == Math.abs(col - sublist.get(i))) return false;
        }
        return true;
    }
    
    private void dfs(int n,
                    List<Integer> sublist,
                    List<List<String>> result){
        if(sublist.size() == n){
            result.add(construct(sublist));
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(!validate(sublist, i)) continue;
            sublist.add(i);
            dfs(n, sublist, result);
            sublist.remove(sublist.size()-1);
        }
    }
    
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new LinkedList<>();
        if(n <= 0){
            result.add(new ArrayList<>());
            return result;
        }
        
        dfs(n, new ArrayList<Integer>(), result);
        
        return result;
    }
}

// idea: col[position], pie[position], na[position]
// we don't need to validate all the back rows each time place a queen on the new row!
// beats over 63% of submission
class Solution {
    private List<String> construct(List<Integer> sublist){
        List<String> result = new LinkedList<>();
        int len = sublist.size();
        for(int i = 0; i < len; i++){
            StringBuilder sb = new StringBuilder();
            for(int j = 0; j < len; j++){
                sb.append(j == sublist.get(i) ? "Q" : ".");
            }
            result.add(sb.toString());
        }
        return result;
    }
    
    private void dfs(int n, 
                     int row, 
                     boolean[] col, 
                     boolean[] pie, 
                     boolean[] na, 
                     List<Integer> sublist, 
                     List<List<String>> result){
        if(row >= n){
            result.add(construct(sublist));
            return;
        }
        
        for(int pos = 0; pos < n; pos++){
            int i = row + pos;   // placed pos
            int j = n - 1 + pos - row;   // placed na
            if(col[pos] || pie[i] || na[j]) continue;
            col[pos] = pie[i] = na[j] = true;
            sublist.add(pos);
            dfs(n, row+1, col, pie, na, sublist, result);
            col[pos] = pie[i] = na[j] = false;
            sublist.remove(sublist.size()-1);
        }
    }
    
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new LinkedList<>();
        if(n <= 0){
            result.add(new ArrayList<>());
            return result;
        }
        
        boolean[] col = new boolean[n];
        boolean[] pie = new boolean[2*n-1];
        boolean[] na = new boolean[2*n-1];
        
        dfs(n, 0, col, pie, na, new ArrayList<>(), result);
        
        return result;
    }
}

// idea: change boolean array to bit array
// beats over 77% of submission
class Solution {
    private List<String> construct(List<Integer> sublist){
        List<String> result = new LinkedList<>();
        int len = sublist.size();
        for(int i = 0; i < len; i++){
            StringBuilder sb = new StringBuilder();
            for(int j = 0; j < len; j++){
                sb.append(j == sublist.get(i) ? "Q" : ".");
            }
            result.add(sb.toString());
        }
        return result;
    }
    
    private void dfs(int n, 
                     int row, 
                     int col, 
                     int pie, 
                     int na, 
                     List<Integer> sublist, 
                     List<List<String>> result){
        if(row >= n){
            result.add(construct(sublist));
            return;
        }
        
        for(int pos = 0; pos < n; pos++){
            int i = row + pos;   // placed pos
            int j = n - 1 + pos - row;   // placed na
            // (a>>i) & 1: read the value on ith bit
            if((( (col>>pos) | (pie>>i) | (na>>j) ) & 1) != 0) continue;
            // a ^= (1<<i): reverse the ith bit
            col ^= (1<<pos);
            pie ^= (1<<i);
            na ^= (1<<j);
            sublist.add(pos);
            dfs(n, row+1, col, pie, na, sublist, result);
            col ^= (1<<pos);
            pie ^= (1<<i);
            na ^= (1<<j);
            sublist.remove(sublist.size()-1);
        }
    }
    
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new LinkedList<>();
        if(n <= 0){
            result.add(new ArrayList<>());
            return result;
        }
        
        int col = 0;
        int pie = 0;
        int na = 0;
        
        dfs(n, 0, col, pie, na, new ArrayList<>(), result);
        
        return result;
    }
}