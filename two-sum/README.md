# Two Sum

Find two numbers whose sum as target and return their indexes.

## Lintcode56
> Description: Given an array of integers, find two numbers such that they add up to a specific target number. The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are zero-based.

Only `O(n) Space, O(nlogn) Time`, and `O(n) Space, O(n) Time` are allowed.

* [HashMap](https://github.com/shinmao/algorithm/blob/master/two-sum/lintcode56-1.java): Use hashmap to solve this problem. Using hashmap to search costs time complexity for O(1), putting element into hashmap costs time complexity for O(n) and space complexity for O(n).