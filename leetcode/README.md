## Leetcode
| Problem        | Solution           | Cheat  | Writeup  |
| ------------- |-------------|-----|-----|
| Maximum Subarray   | [53](./leetcode53-1.java)      ||   |
| Edit Distance    | [72](./leetcode72-1.java)      |:star:|   |
| Longest Increasing Subsequence  | [300](./leetcode300-1.java)      |  |   |
| Longest Common Subsequence  | [1143](./leetcode1143-1.java)      |:star:|   |
| Longest Palindrome Subsequence    | [516](./leetcode516-1.java)      |:star:|   |
| Best Time to Buy and Sell Stock    | [121](./leetcode121-1.java)      |:star:| [wp](https://blog.1pwnch.com/posts/stock-problem-on-leetcode/#121-best-time-to-buy-and-sell-stock)  |
| Best Time to Buy and Sell Stock III   | [123](./leetcode123.java)      |:star:| [wp](https://blog.1pwnch.com/posts/stock-problem-on-leetcode/#123-best-time-to-buy-and-sell-stock-iii)  |
| Best Time to Buy and Sell Stock IV   | [188](./leetcode188.java)      || [wp](https://blog.1pwnch.com/posts/stock-problem-on-leetcode/#188-best-time-to-buy-and-sell-stock-iv)  |
| Best Time to Buy and Sell Stock with Cooldown   | [309](./leetcode309.java)      |:star:| [wp](https://blog.1pwnch.com/posts/stock-problem-on-leetcode/#309-best-time-to-buy-and-sell-stock-with-cooldown)  |
| Best Time to Buy and Sell Stock with Transaction Fee   | [714](./leetcode714.java)      || [wp](https://blog.1pwnch.com/posts/stock-problem-on-leetcode/#714-best-time-to-buy-and-sell-stock-with-transaction-fee)  |
| Maximum Product Subarray    | [152](./leetcode152-1.java)      |:star:|   |
| Degree of an Array    | [697](./leetcode697.java)      ||   |
| Course Schedule    | [207](./leetcode207.java)      || [BFS Topological sort](#bfs-topological-sort)  |
| Course Schedule II   | [210](./leetcode210.java)      || [BFS Topological sort](#bfs-topological-sort)  |
| Course Schedule III   | [630](./leetcode630.java)      |:star:| [Sort in ascending or descending](#sort-in-ascending-order-or-descending-order) |
| Course Schedule IV   | [1462](./leetcode1462.java)      |:star:| Floyd-Warshall |
| Split Array into Consecutive Subsequences   | [659](./leetcode659.java)      |:star:|   |
| Triangle   | [120](./leetcode120.java)      |:star:| [DP](#dp)  |
| Palindrome Partitioning   | [131](./leetcode131.java)      |:star:|  |
| Longest Consecutive Sequence   | [128](./leetcode128.java)      ||  |
| Largest Rectangle in Histogram   | [84](./leetcode84.java)      |:star:| monotonic stack |
| Next Greater Element I   | [496](./leetcode496.java)      || monotonic stack |
| Next Greater Element II   | [503](./leetcode503.java)      || monotonic stack |
| Trapping Rain Water I   | [42](./leetcode42.java)      |:star:| monotonic stack |
| Two Sum   | [1](./leetcode1.java)      || |


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
problem transition can be interpreted as problem relationship. we have found relationship between subproblem and original problem. it can be formulated as `P(x) = min(P(x-2) + 1, P(x-5) + 1)`.  
3. follow actual logic to set initial condition and boundary  
check some cases such as index out of bound. we always need to initialize some state by hands, e.g. `P(0) = 0`.  
4. make sure the order of calculation  
`P(1)`, `P(2)` first or `P(27)`, `P(26)` first? The best way to make sure about order is check formula. When you want to get the result of left side, have you already get the all results of right side?  

> DP is used to optimize the problem of O(2^n), O(n^n), O(n!) to O(n^2), O(n^3), or O(n^4) (Polynomial). If a problem can already be solved in poly time, then DP cannot be used on such problem.

### Time complexity of some core library functions
```java
Arrays.sort(array);
```
This takes `O(nlogn)` of time.