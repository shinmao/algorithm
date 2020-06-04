// Idea: Topological sort
// Important: check cycle in topological sort cannot use record array of visited
// Instead, check number of elements in result
// this solution beats only over 62% of submission on time complexity
// but beat over 100% on space complexity
// so I can also sacrifice space complexity to earn time complexity
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        if(prerequisites == null) return false;
        if(numCourses == 1) return true;
        
        // use topological sort
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
        
        int count = 0;
        while(!queue.isEmpty()){
            int traverse = queue.poll();
            count++;
            for(int course : neighbor.get(traverse)){
                in_deg.set(course, in_deg.get(course) - 1);
                if(in_deg.get(course) == 0){
                    queue.offer(course);
                }
            }
            
        }
        
        return count == numCourses;
    }
}