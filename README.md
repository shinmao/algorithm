## 解題思維
### 利用數據範圍找出思路
一般運算機一秒可以運算 `10^7` ~ `10^9` 次  
我們可以由超時的時間複雜度來估算大概用哪一種演算法可行
| 假設n的大小        | 時間複雜度           | 對應的演算法  |
| ------------- |-------------|-----|
| 10^4   | O(n) / O(nlogn)      | prefix sum, double ptr, DP / sort, binary search |
| 10^3   | O(n^2)      | 2D-DP, 2D array, double loop |
| 10^2   | O(n^3)      | triple loop... |
| 10   | O(2^n), O(n!)      | dfs, recursion |
| 10^9   |       | 別再開array了 |

### 遞迴
遞迴通常會在`return`裏又回call一次function。遞迴是用來**間接**告訴你答案的，而非直接的。某一層做的事都是一樣的，所以我們只要管好自己這層的工作就好。另外遞迴一定會有終止條件(類似在開頭寫個`if() return`之類的)。    
1. 分治法
2. 以遞迴來窮舉(也就是後來的dfs，用於traverse)
3. 又稱作tree search algorithm，以樹狀圖展開所有組合，取代brute force

1. 定義好function
2. 分解每一層的工作
3. 找到停止條件

> 面試的時候還是主動問一下能不能用recursion，通常是可以的！

### Binary search
* [lintcode 183]()
* [leetcode 153](./leetcode/leetcode153.cpp)
* [leetcode 33](./leetcode/leetcode33.cpp)
* [lintcode 438](./lintcode/lintcode438.cpp)

:star: 跳躍法  
```cpp
int cur = start;
for(int jump = (end - start) / 2; jump > 0; jump /= 2) {
    while(cur + jump < end && arr[cur + jump] < target) cur += jump;
}
```
我喜歡把這個寫法叫做rabbit jump。這個寫法找到的是**最後一個小於target的位置**！rabbit從最左邊開始跳，一開始就選最大步，跳到正中間！接下來就是關鍵：我不會馬上換成小步，我會以一樣大的步伐在測看看會不會越界，或者會不會超過target。這也是為什麼內層是用**while而不是if**，用while來最有效率的運用我們最大跨步！注意迴圈的終止條件是當我們接下來的再跳的地方會大於或等於target，所以我們這個rabbit jump找的是最後一個小於target的位置，當然你可以依需求更改條件。  
這是迥然於我們平常用的binary search，我們常常會用左界和右界來限定search space [之前整理的一篇關於binary search的文章](https://blog.1pwnch.com/posts/explore-binary-search/)，唯一要注意的是：這個寫法我們要先確定 `arr[start] < target`，否則最後的結果會錯！

> 如果單純只是想找目標然後又想要偷懶的話(譬如比賽的時候): 建議用lower_bound(iterator, iterator, x)，會回傳第一個 >= x 的位置，時間複雜度也是O(logn)。要注意：如果所有元素都 < x 的話，則會回傳 .end()的位置，是越界的！ 順道提一下upper_bound回傳的則是 > x 的位置。

### Prefix sum 前綴和
* [leetcode 238](./leetcode/leetcode238.cpp)
* [leetcode 560 + 變形題目](./leetcode/leetcode560.cpp)
* [leetcode 209 + 雙指針](./leetcode/leetcode209.cpp)
* [leetcode 862 + 單調棧](./leetcode/leetcode862.cpp)
* [leetcode 644 + binary search](./leetcode/leetcode644.cpp)
* [lintcode 1840 + 二維思想](./lintcode/lintcode1840.cpp)
* [zoj a694 關於二維思想](./zoj/a694.cpp)
很重要的一點：我們應該focus在prefix而非在sum。除了sum之外也可以計算product，甚至紀錄min, max。  
```cpp
prefix_sum[i] = prefix_sum[i - 1] + arr[i];
```
常常用來求**區間**和，我可能還有雙指針和線段樹的選擇。不過切記線段樹不會那麼容易出現。

另外除了上面的式子，一定要記得定義邊界上的值。e.g. 上面當i等於0時就越界了。  
所以prefix sum通常有兩種表示方式：一種是在迴圈裡面用`if i == 0`另外處理prefix sum。  
另外一種則是把**前0個元素prefix sum就是0**的想法寫進實現中。 e.g. 推薦創建`size() + 1`的陣列，然後從0開始，可以省掉很多麻煩...  

> 通常我們會想用O(n^2)去枚舉所有的區間，可是其實O(n^2)還不足以算出區間和，因為列舉出區間[i, j]之後，要把i,j之間的的數字加起來要另外O(n)的時間複雜度...

外面先用一層迴圈把`[0]`到`[i]`的`prefix sum`計算好，如果不想另外開空間也可以直接把結果存在輸入的array上。然後想要做`[0~1]`，`[0~2]`...`[0~n-1]`的判斷的話通常也會在這層迴圈就同時完成。
再來裡面都是處理**非從0開始**的subarray了。`prefix_sum`就可以幫我們把裡面的`O(n)`簡化成`O(1)`：  
```cpp
prefix[right] - prefix[left - i] = sum;
// prefix_sum - prefix_sum' = interval sum
```
這個`[left, right]`則是總和為sum的區間。換句話說，我只要拿兩個`prefix_sum`相減，就可以去看某個區間和囉！  

> subarray相關解有很大概率可以用prefix sum解

### 雙指針
* [leetcode 3](./leetcode/leetcode3.cpp)
* [leetcode 340](./leetcode/leetcode340.cpp)
* [leetcode 76](./leetcode/leetcode76.cpp)
* [leetcode 475(比較不明顯的雙指針)](./leetcode/leetcode475.cpp)
* [lintcode 194](./lintcode/lintcode194.cpp)

### 滑動窗口 sliding window
* [lintcode1849 經典題](./lintcode/lintcode1849.cpp)
* [lintcode1850 隔板法](./lintcode/lintcode1850.cpp)

sliding window通常會先用`O(window-size)`算出初始化的window sum。接下來每往右移一步都只需要考慮最左邊和最右邊的變化就好！  

上面sliding window中有一種配合隔板法的變化題，通常會在同一個數組要求兩個不重合區間的最優解(interval sum之類的)。我們可以列舉隔板將數組分裂成兩塊，那就變成在兩塊中個別求sliding window。目前用起來雖然時間複雜度不是最好，但是思路最清晰！

### BFS 拓墣排序
拓墣 用於有向無環圖，我們可以用它來判斷圖裡有沒有環，如果有那traverse也會失敗。拓墣排序還常拿來判斷兩個點之間有沒有路線，但這樣用 disjoint set 更快更簡潔。

### 動態規劃
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

### 動態規劃：子問題的定義
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

### DFS
dfs竅門:  
```java
opertaion 1
dfs()
operation 2
```
operation 2 would be reverse to offset the operation 1.

### C++ `push_back` v.s. Java `deep copy`
Once confused that we always need to do deep copy in java such like `result.add(new ArrayList<>(list);`; however, we just need to call `push_back(list);` in C++. After I reading the document, I figure out that `push_back` would just add a copied value to the tail of elements. Therefore, we don't need to worry that our operation in future will change the result again!

### 位運算技巧
You can apply bit operation to optimize your time complexity because computer can save the time of converting decimal to binary. For example, applying bit operation is recognized as the most efficient solution for N-Queens on leetcode!  
* [cxyxiaowu bit operation LC problem](https://www.cxyxiaowu.com/8990.html)  
* [BitwiseOperators](https://wiki.python.org/moin/BitwiseOperators)
* [Basics: how to convert negative decimal to binary](https://superuser.com/questions/975684/converting-negative-decimal-to-binary)
* [Basics: What is Bit Masking?](https://stackoverflow.com/questions/10493411/what-is-bit-masking)
* [bit operation](https://oi-wiki.org/math/bit/)