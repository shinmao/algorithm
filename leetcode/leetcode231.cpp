// cool solution
// idea: can only be 1 of 1 bit
// n:    xxxxx1000
// n-1:  xxxxx0111
// &:    xxxxx0000
// beats over 48% of submission
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return (n & (n-1)) == 0;
    }
};

// to be faster than 100% of submission
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        double tmp = log10(n) / log10(2);
        return floor(tmp) == tmp;
    }
};