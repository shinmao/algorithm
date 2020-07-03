// beats over 34% of submission
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        int rightone = x & -x;
        
        vector<int> res = {0, 0};
        for(auto i : nums){
            if((i & rightone) != 0){
                // 1
                res.at(1) ^= i;
            }else{
                // 0
                res.at(0) ^= i;
            }
        }
        
        return res;
    }
};