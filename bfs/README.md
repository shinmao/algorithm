# Breadth First Search

## Binary Tree Level Order Traversal
> Description: Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

* [BFS](https://github.com/shinmao/algorithm/blob/master/bfs/lintcode69-1.java): There are two version of BFS in this version, and there is sharp different performance between them. The second one is the better one that doesn't need to add element for duplicate times to make a waste, adding head of queue instead of adding childs helps me reduce the necessity of checking empty `semi_list`.
> loop過程中一次offer一個到queue就好!

## Number of islands
> Description: Given a boolean 2D matrix, 0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent. Find the number of islands.

* [BFS](https://github.com/shinmao/algorithm/blob/master/bfs/lintcode433-1.java): First, find the master peak of island, which means the first point 1 of each islands, and use BFS to traverse through the island. In the process, make the already traversed nodes become 0 to avoid another island from traversing duplicate nodes.

## Serialize and deserialize the Binary Search Tree
> Description: Design an algorithm and write code to serialize and deserialize a binary tree. Writing the tree to a file is called 'serialization' and reading back from the file to reconstruct the exact same binary tree is 'deserialization'.

* [BFS](https://github.com/shinmao/algorithm/blob/master/bfs/lintcode7-1.java): Dive deep into the comments of this problem!
> 反序列化的過程中可以用node的index來判斷是否treenode的left child

```
Topological sorting 拓樸排序 - 不是一種排序法
多出現在 directed graph
在sort order中每個node只會出現一次
若 A-> B，sort中A也應該在B前面
```

## Topological Sorting
> Description: Given an directed graph, a topological order of the graph nodes is defined as follow: 1. For each directed edge A -> B in graph, A must before B in the order list. 2. The first node in the order can be any node in the graph with no nodes direct to it. Find any topological order for the given graph.

* [BFS](https://github.com/shinmao/algorithm/blob/master/bfs/lintcode127-1/java)

## Course Schedule
> Description: There are a total of n courses you have to take, labeled from 0 to n - 1. Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]. Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

* [BFS](https://github.com/shinmao/algorithm/blob/master/bfs/lintcode615-1.java): Change the prerequisite format back to the neighbor format which we are familiar with, then use simple topological sorting to solve the problem.
> 這題講白了點就是包裝了拓樸排序，先修課程和課程的順序不能弄倒，這就是拓樸排序的特點! 另外要判斷拓樸排序存不存在，只要看排完的時候，有沒有全部的點都排到即可!