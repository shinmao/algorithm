// If greedy, one more thing needed to be care
// if deadline is exceeded, we can try removing course with longest duration in existed schedule
// beats over 85% of submission
// explanation for this problem on leetcode is so nice! Please read!
// analyze subproblem: how to choose between two courses?
class Solution {
    public int scheduleCourse(int[][] courses) {
        if(courses == null) return 0;
        if(courses.length == 1 && courses[0][0] <= courses[0][1]) return 1;
        
        // time of completing courses
        int learn = 0;
        // sort courses with deadline
        Arrays.sort(courses, (a, b) -> a[1] - b[1]);
        // reverse sort courses with duration in existed schedule
        PriorityQueue<Integer> queue = new PriorityQueue<>((a, b) -> b - a);
        
        for(int[] course : courses){
            if(learn + course[0] <= course[1]){
                learn += course[0];
                queue.offer(course[0]);
            }else if(!queue.isEmpty() && course[0] < queue.peek()){
                learn += course[0] - queue.poll();
                queue.offer(course[0]);
            }
        }        
        
        return queue.size();
    }
}