vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size(), 1);
    int pre_product = 1, suf_product = 1;
    for(int i = 0; i < nums.size(); i++) {
        res[i] *= pre_product;
        pre_product *= nums[i];
    }
    for(int i = nums.size() - 1; i > -1; i--) {
        res[i] *= suf_product;
        suf_product *= nums[i];
    }
    return res;
}