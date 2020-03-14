# Window Sum

A window slide through the array with sum.

## lintcode604
> Description: Given an array of n integers, and a moving window(size k), move the window at each iteration from the start of the array, find the sum of the element inside the window at each moving.

Try not to use bruteforce with O(k * n)!

* [solution](https://github.com/shinmao/algorithm/blob/master/window-sum/lintcode604-1.java): While the window sliding through the array, each sum would minus values of the leftmost index and plus the rightmost index of window. e.g. | 1, 2 | 3, 4 | 5, 6 | -> 1 | 2, 3 | 4, 5 | 6.