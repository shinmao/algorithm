import java.util.*;

public class Solution {
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: true if can finish all courses or false
     */
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // true if exist one topological sorting
        if(numCourses == 0 || prerequisites.length == 0){
            return true;
        }
        
        HashMap<Integer, LinkedList<Integer>> map = createMap(numCourses, prerequisites);
        Map<Integer, Integer> in_degree = new HashMap<>();
        // calculate in-degree of nodes
        for(int i = 0; i < numCourses; i++){
            for(Integer course : map.get(i)){
                if(in_degree.containsKey(course)){
                    in_degree.put(course, in_degree.get(course) + 1);
                }else{
                    in_degree.put(course, 1);
                }
            }
        }
        
        int visited = 0;
        Queue<Integer> queue = new LinkedList<>();
        // find the start point
        for(int i = 0; i < numCourses; i++){
            if(!in_degree.containsKey(i)){
                queue.offer(i);
            }
        }
        
        while(!queue.isEmpty()){
            Integer head = queue.poll();
            visited++;
            for(Integer neighbor : map.get(head)){
                in_degree.put(neighbor, in_degree.get(neighbor) - 1);
                
                if(in_degree.get(neighbor) == 0){
                    queue.offer(neighbor);
                }
            }
        }
        
        return visited == numCourses;
    }
    
    private HashMap<Integer, LinkedList<Integer>> createMap(int numCourses, int[][] prerequisites){
        HashMap<Integer, LinkedList<Integer>> map = new HashMap<>();
        
        for(int i = 0; i < numCourses; i++){
            map.put(i, new LinkedList<>());
        }
        for(int i = 0; i < prerequisites.length; i++){
            int pre = prerequisites[i][1];
            int course = prerequisites[i][0];
            map.get(pre).add(course);
        }
        
        return map;
    }
}