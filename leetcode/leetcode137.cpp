// idea: after sorting, the array would become (3), (1), (3), (3)...
// if it is not single, the third element will equal to the first element
// otherwise, the first element will be the single one
// I think the advantage of my idea is that if I find the single one, then I can break out the loop, I don't need to iterate through the whole array
// of course, the worst case is that the single number locate at the tail of array
// beats over 44% of submission
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single;
        sort(nums.begin(), nums.end());   // sort() function takes O(nlogn)
        
        for(int i = 0; i < nums.size(); i+=3){
            if(i == nums.size() - 1) return nums.at(i);  // to avoid index out of bound
            if(nums.at(i+2) != nums.at(i)){
                single = nums.at(i);
                break;
            }
        }
        
        return single;
    }
};

// idea:
// on each of the bits, it must look like (3), (3), (3), ... (1)..
// so we count the number of bit 1 and mod 3
// then we can get the value of the single number on each bit
// only beats over 6% of submission...
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // the number can be negative!
        int result = 0;
        // {b1, b2, b3 ... 32 bit}: means count of 1 on each bit then %3
        for(int i = 0; i < 32; ++i){
            int count = 0;
            for(auto j = nums.begin(); j != nums.end(); ++j){
                if(((*j >> i) & 1) == 1){
                    count += 1;
                }
            }
            result |= (count % 3) << i;
        }
        
        return result;
    }
};

// good reading for following solution:
// https://blog.csdn.net/yutianzuijin/article/details/50597413

// idea:
// beats over 77% of submission
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int high = 0, low = 0;
        for(auto i = nums.begin(); i != nums.end(); ++i){
            int tmp_low = ~high & (low ^ *i);
            high = (high & ~low & ~*i) | (~high & low & *i);
            low = tmp_low;
        }
        return low;
    }
};

// the best solution running in linear time
// idea:
// beats over 99% of submission
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        for(auto i = nums.begin(); i != nums.end(); ++i){
            ones = (ones ^ *i) & ~twos;
            twos = (twos ^ *i) & ~ones;
        }
        
        return ones;
    }
};
