# Binary Search

## Recursion:
```cpp
int binarySearch(vector<int> &a, int start, int end, int target) {
    if(start > end) return -1;
    int mid = start + (end - start) >> 1;
    if(a[mid] == target) return mid;
    if(a[mid] < target) return binarySearch(a, mid + 1, end, target);
    return binarySearch(a, start, mid - 1, target);
}
```
We don't need to care about the case of `start == end`, because neither `(mid + 1, end)` nor `(start, mid - 1)` would cause to `start > end`.

## While-loop: