// 尷尬 這題比賽的時候居然沒有想出來
// 關鍵的地方在於 sliding window和count matched pattern的方式
// AC 100%
bool containsPattern(vector<int>& arr, int m, int k) {
    int matched = 0;
    for(int i = 0; i < arr.size() - m; ++i) {
        if(arr[i] != arr[i + m]) {
            matched = 0;
            continue;
        }
        matched += 1;
        if(matched == (k - 1) * m) return true;
    }
    return false;
}