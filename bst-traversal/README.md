# BST traversal

## Lintcode69
> Description: Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

* [BFS](https://github.com/shinmao/algorithm/blob/master/bst-traversal/lintcode69-1.java): There are two version of BFS in this version, and there is sharp different performance between them. The second one is the better one that doesn't need to add element for duplicate times to make a waste, adding head of queue instead of adding childs helps me reduce the necessity of checking empty `semi_list`.

