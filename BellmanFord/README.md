# Bellman-Ford
It's also used to find the shortest path in the graph. However, there are some difference between Bellman-Ford and Dijkstra.  

* For Dijkstra, the weights of all edges should be non-negative while there can be edges of negative weights in the graph for Bellman-Ford.  
* We use min-priority queue to implement Dijkstra. Each time, we will choose the one with the least distance from the queue to update the distance. However, with Bellman-Ford, we just update distances of each vertices in each loops. What's violent algorithm!  
* Why Bellman-Ford can handle with the edges of negative weights while Dijkstra cannot? The reason is that Bellman-Ford won't separate vertices to two collection, it just relaxs the all edges for `|v| - 1` times. There is no any fixed result that can be changed by nagative edges.

```
// pseudo code
loop for |V| -1 times {
    run relax() for all edges;
}
```  
Therefore, assume there are 5 vertices with 8 edges. We would run `relax()` for 40 times at the end.

# SPFA (Shortest-Path-Faster-Algorithm)
Use queue to optimize Bellman-Ford