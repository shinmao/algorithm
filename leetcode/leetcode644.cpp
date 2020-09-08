// write up
// https://leetcode.com/problems/maximum-average-subarray-ii/discuss/832249/c-detailed-explanation-and-solution-for-binary-search-prefix-sum
bool isLarger(vector<int>& nums, int k, double mid) {
    // assume cur idx: idx
    // Sum: sum differs from average
    // curPreSum: prefix_sum[idx]
    // leftSum: if window maintains k, leftSum is the prefix_sum[idx - k]
    // minLeftSum: the minimum one beyond leftSum
    double curPreSum = 0, leftSum = 0, minLeftSum = 0;
    
    for(int i = 0; i < k; i++)
        curPreSum += nums[i] - mid;
    if(curPreSum - minLeftSum >= 0) return true;
    
    for(int i = k; i < nums.size(); i++) {
        curPreSum += nums[i] - mid;
        leftSum += nums[i - k] - mid;
        minLeftSum = min(minLeftSum, leftSum);
        
        if(curPreSum - minLeftSum >= 0)
            return true;
    }
    
    return false;
}

double findMaxAverage(vector<int>& nums, int k) {
    double left, right, mid;
    left = right = double(nums[0]);
    for(int i = 0; i < nums.size(); i++) {
        left = min(left, double(nums[i]));
        right = max(right, double(nums[i]));
    }
    
    while(left + 1e-5 < right) {
        mid = left + (right - left) / 2;
        if(isLarger(nums, k, mid))
            left = mid;
        else
            right = mid;
    }
    
    return left;
}