int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
    int n = customers.size(), sum = 0;
    // sum for initial sliding window
    for(int i = 0; i < n; i++) {
        if(i < X)
            sum += customers[i];
        else
            sum += customers[i]*(1 - grumpy[i]);
    }
    // slide
    int left = 1, right = X, result = sum;
    while(right < n) {
        // 如果少掉的原本是脾氣差的
        if(grumpy[left - 1] == 1)
            sum -= customers[left - 1];
        // 如果多的原本是脾氣差的
        if(grumpy[right] == 1)
            sum += customers[right];
            
        result = max(result, sum);
        left++;
        right++;
    }
    return result;
}