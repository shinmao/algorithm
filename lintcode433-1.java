class Coordinate {
    int x, y;
    public Coordinate(int x, int y){
        this.x = x;
        this.y = y;
    }
}

public class Solution {
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    public int numIslands(boolean[][] grid) {
        if(grid == null || grid.length == 0 || grid[0].length == 0){
            return 0;
        }
        
        int n = grid.length;
        int m = grid[0].length;
        int num = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    islandPeak(grid, i, j);
                    num++;
                }
            }
        }
        
        return num;
    }
    
    public void islandPeak(boolean[][] grid, int corx, int cory){
        // magic number to get all neighbor
        int[] dirx = {1, 0, 0, -1};
        int[] diry = {0, 1, -1, 0};
        
        Queue<Coordinate> queue = new LinkedList<>();
        queue.offer( new Coordinate(corx, cory) );
        grid[corx][cory] = false;
        while(!queue.isEmpty()){
            Coordinate c = queue.poll();
            for(int i = 0; i < 4; i++){
                Coordinate neighbor = new Coordinate(c.x + dirx[i] , c.y + diry[i]);
                
                // check neighbor outofbound or not
                if(!inScope(neighbor, grid)){
                    continue;
                }
                
                if(grid[neighbor.x][neighbor.y]){
                    grid[neighbor.x][neighbor.y] = false;
                    queue.offer(neighbor);
                }
            }
        }
    }
    
    public boolean inScope(Coordinate node, boolean[][] grid){
        int n = grid.length;
        int m = grid[0].length;
        
        return ( node.x >= 0 && node.x < n && node.y >= 0 && node.y < m);
    }
}