// AC 85.5%
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int head = 0, tail = arr.size() - 1;
    while(tail - head >= k) {
        if(abs(arr[head] - x) > abs(arr[tail] - x)) head++;
        else tail--;
    }
    return vector<int>(arr.begin() + head, arr.begin() + tail +1);
}

// AC 98.5%
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int start = 0, end = arr.size() - k;
    while(start < end) {
        int mid = start + ((end - start) >> 1);
        if(x - arr[mid] > arr[mid + k] - x) start = mid + 1;
        else end = mid;
    }
    return vector<int>(arr.begin() + start, arr.begin() + start + k);
}
