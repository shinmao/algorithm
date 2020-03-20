# Subsets

Given a set of distinct integers, return all possible subsets.  

The thing you should be careful about is in the most inner-side of list, integers need to be listed from small to bigger one.

> When the problem said that, "return all possible sets", then 90% of problems can be solved with DFS.

## lintcode17
* [Recursion](https://github.com/shinmao/algorithm/blob/master/Subset/lintcode17-1.java): Use recursion to solve the problem. Again, to build up a recursion, you just need to think about the relationship between current level and next level. 
```
                    []
               1? /    \
                [1]     []
            2? /   \   /   \
         [1, 2]  [1]  [2]   []
        3?/ \   /  \  /  \ /  \
[1,2,3][1,2][1,3][1][2,3][2][3][]
```
* [DFS](https://github.com/shinmao/algorithm/blob/master/Subset/lintcode17-2.java): Use DFS to solve the problem.
```
                   []
                //   ||    \\   <------------ backtrack
              [1]   [2]    [3]
            // \\    || 
        [1,2] [1,3] [2,3]
        //     
    [1,2,3]
```

## lintcode18
> Description: Given a collection of integers that might contain duplicates, nums, return all possible subsets.

* [DFS](https://github.com/shinmao/algorithm/blob/master/Subset/lintcode18-1.java): Use DFS with if-condition to solve the problem.  
```
                   []
                //   ||    \\
              [1]   [2']   [2'']:x
            // \\    || 
      [1,2'][1,2'']:x[2',2'']
        //     
    [1,2',2'']
```