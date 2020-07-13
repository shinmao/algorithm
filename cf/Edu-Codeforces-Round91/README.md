## Educational Codeforces Round 91 (Rated for Div. 2)

| Challenge        | writeup           | Status  |
| ------------- |:-------------:| -----:|
| A - Three Indices   | [A](./three-indicesA.cpp)      | TLE |
| A - Three Indices   | [A](./three-indicesA-v1.cpp)   |  AC |
| B - One Stop Solution   | [B](./one-stop-solutionB.cpp)   |  AC |

## Writeup
1. Three Indices: I don't know why BST comes to my mind at first when I run into this challenge. I spend much time on implementing the binary search tree. The logic and answer seems right when the size of input is still small; however, it ran into TLE with larger input size. The AC solution is based on the concept that if there is i, j, k that i < j and j > k. Then they must can be on continuous indices because they are only two relationship between pair of numbers: larger or smaller (equal).
2. One Stop Solution: Before we start, we must know that the position is not the matter because all of the characters will roll for a round. To remain the biggest win in each round, we just need to find the most frequent in the string, and beat it. For example, string is `RPP`, the most frequent one is `P`, I can choose all `S` to remain that each time I can get two wins (against `P`).