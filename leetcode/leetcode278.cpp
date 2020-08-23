// beats over 81%
class Solution {
public:
    int firstBadVersion(int n) {
        if(n <= 0) return -1;
        if(n == 1) {
            if(isBadVersion(1)) return 1;
            else return -1;
        }
        int start = 1, end = n, mid = 1;
        while(start <= end) {
            mid = start + ((end - start) >> 1);
            if(isBadVersion(mid) == false) start = mid + 1;
            else {
                if(isBadVersion(mid - 1) == false) return mid;
                else end = mid - 1;
            }
        }
        return -1;
    }
};

// beats over 100%
int firstBadVersion(int n) {
    if(n <= 0) return -1;
    if(n == 1) {
        if(isBadVersion(1)) return 1;
        else return -1;
    }
    int start = 1, end = n, mid = 1;
    while(start < end) {
        mid = start + ((end - start) >> 1);
        if(!isBadVersion(mid)) start = mid + 1;
        else end = mid;
    }
    return (isBadVersion(start) ? start : -1);
}