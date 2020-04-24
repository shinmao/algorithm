package com.company;
import com.company.Vertex;
import java.util.*;
import java.lang.*;

public class Dijkstra {
    private int dist[];
    private Set<Integer> s;
    private PriorityQueue<Vertex> pq;
    private int num;
    List<List<Vertex>> adj;

    public Dijkstra(int num) {
        // number of vertices
        this.num = num;
        // initialize distance
        dist = new int[num];
        // finished set
        s = new HashSet<Integer>();
        pq = new PriorityQueue<Vertex>(num, new Vertex());
    }

    public void initialize(List<List<Vertex>> adj, int source){
        // init adj list
        this.adj = adj;
        // init s
        s.add(source);
        // init pq
        pq.add(new Vertex(source, 0));
        // init dist
        dist[0] = 0;
        for (int i = 1; i < num; i ++){
            dist[i] = Integer.MAX_VALUE;
        }
    }

    public void body(){
        // algorithm body
        while(s.size() != num){
            Vertex min = pq.poll();
            s.add(min.index);
            // update dist[]
            for(Vertex neighbor : adj.get(min.index)){   // neighbor of min
                if(!(s.contains(neighbor.index))){
                    // compare ( current dist[neighbor], current dist[finished] + distance(finished -> neighbor) )
                    dist[neighbor.index] = Integer.min(dist[neighbor.index], dist[min.index] + neighbor.weight);
                    pq.offer(new Vertex(neighbor.index, dist[neighbor.index]));
                }
            }

        }
    }

    public static void main(String[] args) {
        int num = 5;
        int source = 0;

        List<List<Vertex>> adj = new ArrayList<List<Vertex>>();
        for(int i = 0; i < num; i ++){
            List<Vertex> list = new ArrayList<Vertex>();
            adj.add(list);
        }
        adj.get(0).add(new Vertex(1, 9));
        adj.get(0).add(new Vertex(2, 6));
        adj.get(0).add(new Vertex(3, 5));
        adj.get(0).add(new Vertex(4, 3));
        adj.get(2).add(new Vertex(1, 2));
        adj.get(2).add(new Vertex(3, 4));

        Dijkstra dgraph = new Dijkstra(num);
        dgraph.initialize(adj, source);
        dgraph.body();

        for(int i = 0; i < dgraph.dist.length; i++){
            System.out.println("The shortest path from " + source + " to " +  i + " is " + dgraph.dist[i]);
        }
    }
}
