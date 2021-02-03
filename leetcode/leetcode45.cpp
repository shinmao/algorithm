/**
 * dp的寫法很直觀，但會TLE
 * 推測承受不住O(n^2)的時間複雜度
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> min_step(n, INT_MAX);
        min_step[0] = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] + j >= i)
                    min_step[i] = min(min_step[i], min_step[j] + 1);
            }
        }
        return min_step[n - 1];
    }
};
/**
 * 貪心法：O(n)
 * 這題花了點時間理解code
 * 其實choice_end跟farest差不多
 * 思路：找尋有潛力的位置
 * 3 可以選擇落在 1, 4, 2
 * 那肯定選擇4呀，因為4可以讓它到最遠的位置
 * 讓choice_end等同於farest限制jmp數
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jmps = 0;
        int choice_end = 0, farest = 0;
        
        for(int i = 0; i < n - 1; i++) {
            farest = max(farest, i + nums[i]);
            // 從目前的 i 到 choice_end，都是可以選擇跳的目的
            // 在這期間，找尋有潛力的位置
            if(i == choice_end) {
                jmps++;
                choice_end = farest;
            }
        }
        
        return jmps;
    }
};