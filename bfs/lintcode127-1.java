import java.util.*;
/**
 * Definition for Directed graph.
 * class DirectedGraphNode {
 *     int label;
 *     ArrayList<DirectedGraphNode> neighbors;
 *     DirectedGraphNode(int x) { label = x; neighbors = new ArrayList<DirectedGraphNode>(); }
 * };
 */

public class Solution {
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    public ArrayList<DirectedGraphNode> topSort(ArrayList<DirectedGraphNode> graph) {
        if(graph.isEmpty() || graph == null){
            return null;
        }
        Map<DirectedGraphNode, Integer> map = new HashMap<>();
        Queue<DirectedGraphNode> queue = new LinkedList<>();
        ArrayList<DirectedGraphNode> result = new ArrayList<>();
        
        // calculate in-degree of access nodes (which is not start node)
        for(DirectedGraphNode node : graph){
            for(DirectedGraphNode neighbor : node.neighbors){
                if(map.containsKey(neighbor)){
                    map.put(neighbor, map.get(neighbor) + 1);
                }else{
                    map.put(neighbor, 1);
                }
            }
        }
        
        // add the start point to queue
        for (DirectedGraphNode node : graph) {
            if(!map.containsKey(node)){
                queue.offer(node);
            }
        }
        
        while(!queue.isEmpty()){
            DirectedGraphNode head = queue.poll();
            result.add(head);
            for(DirectedGraphNode neighbor : head.neighbors){
                map.put(neighbor, map.get(neighbor) - 1);
                
                if(map.get(neighbor) == 0){
                    queue.offer(neighbor);
                }
            }
        }
        
        return result;
    }
}