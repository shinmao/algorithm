// 這題非常有意思
// 看起來因為題目的限制沒有單調性所以不能用雙指針去解
// 還是想出了規律用相向雙指針解決問題
// 排序數組後會發現原本的L和R指針在題目的數組中都會向左移到頂點再向右移
// 只要按照正負數區分情況就好
inline int nextR(vector<int> &nums, int cur) {
    // 若原本是正數，則向左移
    if(nums[cur] > 0) {   // -> left
        for(int i = cur - 1; i >= 0; i--) {
            if(nums[i] > 0)
                return i;
        }
        // 移到最左邊了 則向右移
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= 0)
                return i;
        }
        return -1;
    }
    // 若原本是負數，則繼續向右移
    for(int i = cur + 1; i < nums.size(); i++) {
        if(nums[i] <= 0)
            return i;
    }
    return -1;
}

inline int nextL(vector<int> &nums, int cur) {
    if(nums[cur] < 0) {   // -> left
        for(int i = cur - 1; i >= 0; i--) {
            if(nums[i] < 0)
                return i;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0)
                return i;
        }
        return -1;
    }
    for(int i = cur + 1; i < nums.size(); i++) {
        if(nums[i] >= 0)
            return i;
    }
    return -1;
}

vector<vector<int>> twoSumVII(vector<int> &nums, int target) {
    vector<vector<int>> res;
    int left = 0, right = 0;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] < nums[left])
            left = i;
        if(nums[i] > nums[right])
            right = i;
    }
    // 跟平常的left < right 不一樣
    // left, right指向的是原本排序好的數組中應該指向的位置
    // 在新數組中的位置是用跳的罷了
    // 每一次求完指針下一個位置
    // 我們都要去檢查-1，因為它代表沒有下一個位置了 即可break
    while(nums[left] < nums[right]) {
        int sum = nums[left] + nums[right];
        if(sum >= target) {
            if(sum == target) {
                vector<int> sub;
                sub.push_back(left);
                sub.push_back(right);
                sort(sub.begin(), sub.end());
                res.push_back(sub);
                left = nextL(nums, left);
                if(left == -1)
                    break;
            }else {
                right = nextR(nums, right);
                if(right == -1)
                    break;
            }
        }else {
            left = nextL(nums, left);
            if(left == -1)
                break;
        }
    }
    
    return res;
}
