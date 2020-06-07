// why cannot use greedy?
// assume the left child is smaller then right child
// with greedy, we would choose left child
// however, next childs of left child are all bigger than those of right child
// which means left child would not be the good choice anymore
// DP, beats over 98% of submission, O(n^2)
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if(triangle == null || triangle.size() == 0) return -1;
        if(triangle.get(0) == null || triangle.get(0).size() == 0) return -1;
        
        int n = triangle.size();
        // sum[x][y]: minimum path sum from (x, y) to bottom
        int[][] sum = new int[n][n];
        
        // init sum of botton line
        for(int i = 0; i < n; i++){
            sum[n - 1][i] = triangle.get(n-1).get(i);
        }
        
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                sum[i][j] = Math.min(sum[i+1][j], sum[i+1][j+1]) + triangle.get(i).get(j);
            }
        }
        
        return sum[0][0];
    }
}

// if use DFS to traverse
// traverse(triangle, x+1, y, sum + triangle.get(x).get(y))
// traverse(triangle, x+1, y+1, sum + triangle.get(x).get(y))
// update minimum sum
// O(2^n): there are at most 2^n nodes

// if use DFS + D&C
// subproblems are left child and right child
// left = divide_conquer(triangle, x+1, y)
// right = divide_conquer(triangle, x+1, y+1)
// min(left, right) + triangle.get(x).get(y)
// O(2^n): also will go through all the nodes