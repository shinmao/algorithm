# Binary Search

* [This is important template of Binary Search](./leetcode704-1.java)

1. Use while loop to tighten the scope from n to 2(only start and end).  
2. Check whether target in [start, end]

Q: Use `start+1 < end` instead of `start < end` or `start <= end`  
> dead loop happens in the last loop because our start would be smaller than end forever

Q: Use `start = mid` instead of `start = mid + 1`  
> Sometime, mid +1/-1 would cause you lose some solution. Therefore, start = mid would be the better solution for convenience