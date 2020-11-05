class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // write your code here
        if(numCourses == 0 || prerequisites.size() == 0) 
            return true;
            
        vector<vector<int>> preq(numCourses);
        vector<int> in_degree(numCourses, 0);
        
        // calculate in degree of each nodes
        for(int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i].first;
            int pre = prerequisites[i].second;
            preq[pre].push_back(course);
            in_degree[course]++;
        }
        
        queue<int> q;
        for(int i = 0; i < in_degree.size(); i++) {
            if(in_degree[i] == 0)
                q.push(i);
        }
        
        vector<int> path;
        while(!q.empty()) {
            int head = q.front();
            q.pop();
            path.push_back(head);
            for(auto it : preq[head]) {
                if(--in_degree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        return path.size() == numCourses;
    }
};