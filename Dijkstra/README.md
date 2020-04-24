# Dijkstra
Here I use min-priority queue in java to implement Dijkstra algorithm.  
`Dijkstra.java` is the main class to run the algorithm.  
`Vertex.java` is the imported class to create graph.

![](https://github.com/shinmao/algorithm/blob/master/Dijkstra/graph.png)  

* Someone would write an additional `ExtractMin()` to help find out the smallest `dist[]` in queue. In fact, the second parameter of `PriorityQueue` accepts a comparator. We can override the comparator of vertex interface to follow the ordering of `dist`. When we use `PriorityQueue(num of vertices, new Vertex())`, we just need to find the head element then we can get the one with smallest distance.