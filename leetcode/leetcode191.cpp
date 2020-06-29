// beats over 49% of submission
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n != 0){
            n &= n-1;
            count++;
        }
        
        return count;
    }
};