import java.util.ArrayList;
import java.util.List;

public class BellmanFord {
    private int num;
    private List<List<Vertex>> edge;
    private int[] dist;
    private int[] pre;

    BellmanFord(int num, List<List<Vertex>> edge){
        this.num = num;
        this.dist = new int[num];
        this.pre = new int[num];
        this.edge = edge;
    }

    void init(){
        // pre all set to -1
        for(int i = 0; i < num; i++){
            pre[i] = -1;
        }
        // set dist
        for(int i = 0; i < num; i++){
            if(i == 0){
                dist[i] = 0;
            }else{
                dist[i] = Integer.MAX_VALUE;
            }
        }
    }

    void bf(){
        int count = 0;
        while(count < num) {
            for (int i = 0; i < num; i++) {
                for (Vertex v : edge.get(i)) {
                    if (dist[i] != Integer.MAX_VALUE && dist[i] + v.weight < dist[v.index]) {
                        dist[v.index] = dist[i] + v.weight;
                        pre[v.index] = i;
                    }
                }
            }
            count++;
        }
        if(chk_ncycle()){
            return;
        }else{
            ptDist();
        }
    }

    boolean chk_ncycle(){
        for(int i = 0; i < num; i++){
            for(Vertex v : edge.get(i)){
                if(dist[i] != Integer.MAX_VALUE && dist[v.index] > dist[i] + v.weight){
                    System.out.println("Graph contains negative weight cycle!");
                    return true;
                }
            }
        }
        return false;
    }

    void ptDist(){
        for(int i = 0; i < num; i++){
            System.out.println("From 0 to " + i + ": " + dist[i]);
        }
    }

    public static void main(String[] args){
        int num = 6;   // number of vertices

        List<List<Vertex>> edge = new ArrayList<>();
        for(int i = 0; i < num; i++){
            List<Vertex> list = new ArrayList<>();
            edge.add(list);
        }
        edge.get(0).add(new Vertex(1, 5));
        edge.get(1).add(new Vertex(2, 6));
        edge.get(1).add(new Vertex(4, -4));
        edge.get(2).add(new Vertex(4, -3));
        edge.get(2).add(new Vertex(5, -2));
        edge.get(3).add(new Vertex(2, 4));
        edge.get(4).add(new Vertex(3, 1));
        edge.get(4).add(new Vertex(5, 6));
        edge.get(5).add(new Vertex(0,3));
        edge.get(5).add(new Vertex(1, 7));

        BellmanFord bellman = new BellmanFord(num, edge);
        bellman.init();
        bellman.bf();
    }
}
