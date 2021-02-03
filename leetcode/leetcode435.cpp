/**
 * 思路：把所有區間按照end升序排列
 * first end-> 刪除重疊區間 ->second end -> 刪除重疊區間...
 */
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        if(a[1] == b[1])
            return a[0] > b[0];
        return a[1] < b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0 || n == 1)
            return 0;
        
        int count = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int prev_end = intervals[0][1];
            
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] < prev_end)
                count++;
            else
                prev_end = intervals[i][1];
        }
        
        return count;
    }
};