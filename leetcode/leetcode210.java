// Idea: same, topological sort
// only beats over 54% of submission for time complexity
// instead, beats over 97% of submission for space complexity
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        if(prerequisites == null) return new int[]{};
        if(numCourses == 1) return new int[]{0};
        
        List<List<Integer>> neighbor = new ArrayList<>();
        List<Integer> in_deg = new ArrayList<>();
        for(int i = 0; i < numCourses; i++){
            List<Integer> l = new ArrayList<>();
            neighbor.add(l);
            in_deg.add(0);
        }
        
        for(int i = 0; i < prerequisites.length; i++){
            // put prerequisites into edge
            // prerequisites[i] = {}: neighbor of course i
            neighbor.get(prerequisites[i][1]).add(prerequisites[i][0]);
            // calculate in-degree for each course
            in_deg.set(prerequisites[i][0], in_deg.get(prerequisites[i][0]) + 1);
        }
        
        Queue<Integer> queue = new LinkedList<>();
        
        // put all the course with 0 in-degree into queue
        for(int i = 0; i < numCourses; i++){
            if(in_deg.get(i) == 0){
                queue.offer(i);
            }
        }
        
        List<Integer> result = new ArrayList<>();
        while(!queue.isEmpty()){
            int traverse = queue.poll();
            result.add(traverse);
            for(int course : neighbor.get(traverse)){
                in_deg.set(course, in_deg.get(course) - 1);
                if(in_deg.get(course) == 0){
                    queue.offer(course);
                }
            }
        }
        
        int[] schedule = new int[numCourses];
        if(result.size() == numCourses){
            for(int i = 0; i < numCourses; i++){
                schedule[i] = result.get(i);
            }
        }else{
            return new int[]{};
        }
        
        return schedule;
    }
}