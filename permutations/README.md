# Permutations

Return all possible sequences.

## lintcode15
> Description: Given a list of numbers, return all possible permutations.

* [DFS](https://github.com/shinmao/algorithm/blob/master/permutations/lintcode15-1.java): Here I use DFS with visited array which is used to record visited nodes to solve the problem.
>  在subset的寫法中有用index來避免return [1, 2] 後又 return [2, 1]，此題排列組合的情況下需要的就不是只有往後找，而是列入還沒訪問過的元素！

## lintcode16
> Description: Given a list of numbers with duplicate number in it. Find all unique permutations.

* [DFS](https://github.com/shinmao/algorithm/blob/master/permutations/lintcode16-1.java)
> 這題只要從上面15稍加修改就可以得到答案，關鍵在於重複的排列要如何選擇。這裡當我遇到[1, 2', 2'']和[1, 2'', 2']時，我會選擇[1,2',2'']。所以除了之前的訪過條件外，再加個 同樣的元素會按照index排列 就能夠成功了！ (換句話說，就是2'一定要在2''之前被訪問過)