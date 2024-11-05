class Solution {
public:
    // 因為n只有10^2，直接用暴力解全部visit過一遍也可以
    int removeElement(vector<int>& nums, int val) {
        vector<int> final_num;
        int cnt = nums.size();
        for (int i = 0; i < cnt; ++i) {
            if (nums[i] == val) {
                // rm element 
                nums[i] = NULL;
            } else {
                final_num.push_back(nums[i]);
            }
        }

        nums.clear();
        for (int i = 0; i < final_num.size(); ++i) {
            nums.push_back(final_num[i]);
        }
        int curr_cnt = final_num.size();
        while (curr_cnt < cnt) {
            nums.push_back(NULL);
            curr_cnt += 1;
        }

        return final_num.size();
    }

    // 這個快慢指針的方法就簡潔很多了！！
    int removeElement(vector<int>& nums, int val) {
        int slowidx = 0;
        for (int fastidx = 0; fastidx < nums.size(); ++fastidx) {
            if (nums[fastidx] != val) {
                // 用slowidx來表示目前已經插入新元素到哪裡一個idx了 
                nums[slowidx] = nums[fastidx];
                slowidx++;
            }
        }

        // 由於前面插入完就會先移到下一位，所以這裡的idx就是count
        return slowidx;
    }
};