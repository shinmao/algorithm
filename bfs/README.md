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