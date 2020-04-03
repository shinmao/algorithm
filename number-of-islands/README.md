# Number of islands

## Lintcode433
> Description: Given a boolean 2D matrix, 0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent. Find the number of islands.

* [BFS](https://github.com/shinmao/algorithm/blob/master/number-of-islands/lintcode433-1.java): First, find the master peak of island, which means the first point 1 of each islands, and use BFS to traverse through the island. In the process, make the already traversed nodes become 0 to avoid another island from traversing duplicate nodes.