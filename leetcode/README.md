## Leetcode
| Problem        | Solution           | Cheat  | Writeup  |
| ------------- |-------------|-----|-----|
| Maximum Subarray   | [53](./leetcode53.java)      ||   |
| Edit Distance    | [72](./leetcode72.java)      |:star:|   |
| Longest Increasing Subsequence  | [300](./leetcode300.java)      |  |   |
| Longest Common Subsequence  | [1143](./leetcode1143.java)      |:star:|   |
| Longest Palindrome Subsequence    | [516](./leetcode516.java)      |:star:|   |
| Best Time to Buy and Sell Stock    | [121](./leetcode121.java)      |:star:| [wp](https://blog.1pwnch.com/posts/stock-problem-on-leetcode/#121-best-time-to-buy-and-sell-stock)  |
| Best Time to Buy and Sell Stock III   | [123](./leetcode123.java)      |:star:| [wp](https://blog.1pwnch.com/posts/stock-problem-on-leetcode/#123-best-time-to-buy-and-sell-stock-iii)  |
| Best Time to Buy and Sell Stock IV   | [188](./leetcode188.java)      || [wp](https://blog.1pwnch.com/posts/stock-problem-on-leetcode/#188-best-time-to-buy-and-sell-stock-iv)  |
| Best Time to Buy and Sell Stock with Cooldown   | [309](./leetcode309.java)      |:star:| [wp](https://blog.1pwnch.com/posts/stock-problem-on-leetcode/#309-best-time-to-buy-and-sell-stock-with-cooldown)  |
| Best Time to Buy and Sell Stock with Transaction Fee   | [714](./leetcode714.java)      || [wp](https://blog.1pwnch.com/posts/stock-problem-on-leetcode/#714-best-time-to-buy-and-sell-stock-with-transaction-fee)  |
| Maximum Product Subarray    | [152](./leetcode152.java)      |:star:|   |
| Degree of an Array    | [697](./leetcode697.java)      ||   |
| Course Schedule    | [207](./leetcode207.java)      || [BFS Topological sort](#bfs-topological-sort)  |
| Course Schedule II   | [210](./leetcode210.java)      || [BFS Topological sort](#bfs-topological-sort)  |
| Course Schedule III   | [630](./leetcode630.java)      |:star:| [Sort in ascending or descending](#sort-in-ascending-order-or-descending-order) |
| Course Schedule IV   | [1462](./leetcode1462.java)      |:star:| Floyd-Warshall |
| Split Array into Consecutive Subsequences   | [659](./leetcode659.java)      |:star:|   |
| Triangle   | [120](./leetcode120.java)      |:star:| [DP](#dp)  |
| Palindrome Partitioning   | [131](./leetcode131.java)      |:star:|  |
| Palindrome Partitioning II   | [132](./leetcode132.java)      |:star:|  |
| Longest Consecutive Sequence   | [128](./leetcode128.java)      ||  |
| Largest Rectangle in Histogram   | [84](./leetcode84.java)      |:star:| monotonic stack |
| Next Greater Element I   | [496](./leetcode496.java)      || monotonic stack |
| Next Greater Element II   | [503](./leetcode503.java)      || monotonic stack |
| Trapping Rain Water I   | [42](./leetcode42.java)      |:star:| monotonic stack |
| Two Sum   | [1](./leetcode1.java)      || |
| Wildcard Matching   | [44](./leetcode44.java)      |:star:| [DP](#dp) |
| Regular Expression Matching   | [10](./leetcode10.java)      |:star:| [DP](#dp) |
| Word Break   | [139](./leetcode139.java)      |:star:| |
| Word Break II   | [140](./leetcode140.java)      |:star:| |
| Word Break III   | [140's modified](./leetcode140-1.java)     |:star:| |
| Subsets   | [78](./leetcode78.java)     |:star:| [DFS](#dfs) |
| Subsets II   | [90](./leetcode90.java)     |:star:| [DFS](#dfs) |
| Permutations   | [46](./leetcode46.java)     |:star:| [DFS](#dfs) |
| Permutations II  | [47](./leetcode47.java)     |:star:| [DFS](#dfs) |
| Combination Sum  | [39](./leetcode39.java)     || [DFS](#dfs) |
| Combination Sum II  | [40](./leetcode40.java)     || [DFS](#dfs) |


## Notes
### BFS Topological sort
Topological is used on the directed acyclic graph, seriously follow the order of **dependance**. We also can use it to check the cycle: If cycle exists, topological sort won't success, which means that we can not traverse all nodes.

### Sort in ascending order or descending order
For sorting method in core library  
For Array:  
```java
Arrays.sort(array, comparator);
```  
For List:  
```java
Collections.sort(list, comparator);
```  
For priority queue:  
```java
PriorityQueue<E> queue = new PriorityQueue<>(comparator);
```  
comparator in ascending order:  
```java
(a, b) -> a - b
```  
comparator in descending order:  
```java
(a, b) -> b - a
```

### DP
1. make sure problem state  
we usually create an array for DP, we should make sure what each elements represents for first, which is also mean make sure problem state.  
First, **the state before the last step**. Take coins problem to get minimum number of coins for example, we want the sum of coins to be 27, then the state before the last step should be **(27 - ak)** if our coins are a1, a2, ...ak, ai can be 2 or 5.  
Second, **define subproblem**. So, what is the minimum number of coins whose sum is (27 - ak)? This is a subproblem. Now, we can **find the relationship between subproblem and original problem**. ak should be 2 or 5, so `P(27) = P(27 - 2) + 1` or `P(27) = P(27 - 5) + 1`.  
2. formulate problem transition  
problem transition can be interpreted as problem relationship, and **remember don't be confused by other states, only consider the two states**. we have found relationship between subproblem and original problem. it can be formulated as `P(x) = min(P(x-2) + 1, P(x-5) + 1)`.  
3. follow actual logic to set initial condition and boundary  
check some cases such as index out of bound. we always need to initialize some state by hands, e.g. `P(0) = 0`.  
4. make sure the order of calculation  
`P(1)`, `P(2)` first or `P(27)`, `P(26)` first? The best way to make sure about order is check formula. When you want to get the result of left side, have you already get the all results of right side?  

> DP is used to optimize the problem of O(2^n), O(n^n), O(n!) to O(n^2), O(n^3), or O(n^4) (Polynomial). If a problem can already be solved in poly time, then DP cannot be used on such problem.

Another way to handle with DP problem: Brute force or DFS first, and try to add some memoization to optimize it.  

### DP: Def for subproblem
```java
dp[i]
```
* from index i to tail  
* from index 0 to i  
* first i  

```java
dp[i][j]
```
* from index i to j  
* first i in first sequence and first j in second sequence
* index i to tail in first sequence and index j to tail in second sequence

> subproblem asks the same question as original (most of all), e.g. how many palindrome can we get? then our subproblem is also getting number of palindrome from substring.

### Time complexity of some core library functions
```java
Arrays.sort(array);
```
This takes `O(nlogn)` of time.

### Default value of data structure
* The defualt value of boolean array is **false** (in java).

### DFS
The trick of dfs:  
```java
opertaion 1
dfs()
operation 2
```
operation 2 would be reverse to offset the operation 1.

### Deep copy
First comes up with a question?  
```java
func(x){
    x = x + 1;
}

main(){
    int x = 0;
    func(x);
    // x is still 0
}

func(subset){
    subset.add(1);
}

main(){
    new subset;
    func(subset);
    // subset: {1}
}
```
Why? The reason is **the change to the parameter itself**. When we call function, we would always pass the reference. When we use `param = ...`, it would change itself **(we can imagine it creates a new x)**, and the change is only valid in the function. However, `param.func()` won't change itself, so the add operation would also valid while back to main function. So, if we want to change it, we should use `param = ...` to do a deep copy like following:  
```java
newSet = new ArrayList<Integer>(subset);
results.add(newSet);
```