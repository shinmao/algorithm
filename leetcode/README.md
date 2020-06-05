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
| Split Array into Consecutive Subsequences   | [659](./leetcode659.java)      |:star:|   |

## Notes
### BFS Topological sort
Topological is used on the directed acyclic graph, seriously follow the order of **dependance**. We also can use it to check the cycle: If cycle exists, topological sort won't success, which means that we can not traverse all nodes.

### Sort in ascending order or descending order
For sorting method in core library  
For Array:  
ˋˋˋjava
Arrays.sort(array, comparator);
ˋˋˋ  
For List:  
ˋˋˋjava
Collections.sort(list, comparator);
ˋˋˋ  
For priority queue:  
ˋˋˋjava
PriorityQueue<E> queue = new PriorityQueue<>(comparator);
ˋˋˋ  
comparator in ascending order:  
ˋˋˋjava
(a, b) -> a - b
ˋˋˋ  
comparator in descending order:  
ˋˋˋjava
(a, b) -> b - a
ˋˋˋ