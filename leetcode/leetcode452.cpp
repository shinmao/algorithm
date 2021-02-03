/**
 * 思路：簡而言之就是區間問題
 * 發現有重疊的區間，就不需要多射一把箭
 */
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        if(a[1] == b[1])
            return a[0] > b[0];
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        
        sort(points.begin(), points.end(), cmp);
        
        int count = 1, prev_end = points[0][1];
        for(int i = 1; i < n; i++) {
            if(points[i][0] <= prev_end)
                continue;
            else
                prev_end = points[i][1];
            count++;
        }
        
        return count;
    }
};