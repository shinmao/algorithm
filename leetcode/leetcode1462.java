// we cannot use topological for this problem
// topological will give an order based on dependance, but won't give traversal path
// But if I choose to use BFS and trace for each query, it will TLE!
// We need an algorithm for all pairs path!
// Here I use Floyd-Warshall but I don't need to find shortest path
// beats over 63% of submission
class Solution {
    public List<Boolean> checkIfPrerequisite(int n, int[][] prerequisites, int[][] queries) {
        List<Boolean> result = new ArrayList<>();
        if(prerequisites.length == 0){
            for(int[] i : queries){
                result.add(false);
            }
            return result;
        }

        boolean[][] connected = new boolean[n][n];
        for(int[] pre : prerequisites){
            connected[pre[0]][pre[1]] = true;
        }
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    connected[i][j] = connected[i][j] || (connected[i][k] && connected[k][j]);
                }
            }
        }
        
        for(int[] query : queries){
            if(connected[query[0]][query[1]]){
                result.add(true);
            }else{
                result.add(false);
            }
        }
        
        return result;
    }
}