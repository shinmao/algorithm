public class FloydWarshall {
    private static final int INF = 999;
    private int[][] graph;
    private int num;

    public FloydWarshall(int[][] graph, int num){
        this.graph = graph;
        this.num = num;
    }

    void fw(){
        for(int k = 0; k < num; k++){
            for(int i = 0; i < num; i++){
                for(int j = 0; j < num; j++){
                    if(graph[i][k] + graph[k][j] < graph[i][j]){
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }

    void ptDst(){
        for(int i = 0; i < num; i++){
            for(int j = 0; j < num; j++){
                System.out.println("[" + i + "]" + "[" + j + "]: " + graph[i][j]);
            }
        }
    }

    public static void main(String[] args){
        int num = 4;
        int graph[][] = {
                {0, 3, INF, 5},
                {2, 0, INF, 4},
                {INF, 1, 0, INF},
                {INF, INF, 2, 0}
        };
        FloydWarshall fw = new FloydWarshall(graph, num);
        fw.fw();
        fw.ptDst();
    }
}
