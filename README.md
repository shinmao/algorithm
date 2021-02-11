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

### 出題頻率 by TA
#### 很常见
* bfs/dfs
* 经典题：word ladder, word break, k largest...
* 模拟（题目叫你做什么，你就做什么） Strange sort problem  Interger -> roman 
#### 非常常见
* 二叉树、dp（背包、序列型dp、坐标型、双序列型（Longest Common Substring/Subsequence）、常见问题（L Increasing Subsequence，L Palindrome String））
、二分答案、前缀和与双指针
* LRU、LFU，linkedlist（快慢指针，copy linkedlist with random pointer），扫描线和一些简单的数据结构
（treemap, hashmap, heap， union find，trie...)
#### 考得很少
* 二分搜索（二分数值），比较难的dp（状压dp（Travel Salesman Problem），概率dp，区间dp），（手写）红黑树，dfs的非递归实现，矩阵快速幂
* dij, spfa, KMP ...

### 資料結構的妙用
#### Stack
* [leetcode 20 判斷括號合法性](./leetcode/leetcode20.cpp)

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
* [lintcode 258](./lintcode/lintcode258.cpp)

三種模版了解一下：  
```cpp
// I.
while(start <= end) {
    if(nums[mid] == target)
        return mid;
    else if(nums[mid] > target)
        end = mid - 1;
    else
        start = mid + 1;
}
// II.
while(start < end) {
    if(nums[mid] == target)
        return mid;
    if(nums[mid] < target)
        start = mid + 1;
    else
        end = mid;
}
if(start != num.size() && nums[start] == target)
    return start;
// III.
while(start + 1 < end) {
    if(nums[mid] == target)
        return mid;
    if(nums[mid] < target)
        start = mid;
    else
        end = mid;
}
if(nums[start] == target)
    return start;
if(nums[end] == target)
    return end;
// left bound
int start = 0, end = nums.size() - 1;
while(start <= end) {
    int mid = start + (end - start) >> 1;
    if(nums[mid] < target) {
        left = mid + 1;
    }else if(nums[mid] > target){
        right = mid - 1;
    }else if(nums[mid] == target) {
        right = mid - 1;
    }
}
// 我們要回傳left，上面我們一直把left往右加，所以要先檢查left有沒有超出最右界
if(left >= nums.size() || nums[left] != target)
    return -1;
return left;
// right bound
while(start <= end) {
    int mid = start + (end - start) >> 1;
    if(nums[mid] < target) {
        left = mid + 1;
    }else if(nums[mid] > target) {
        right = mid - 1;
    }else if(nums[mid] == target) {
        left = mid + 1;
    }
}
if(right < 0 || nums[right] != target)
    return -1;
return right;
```  

:star: 再次更新  
感謝@labuladong  
其實上面三種模板通通可以用`[]`都方法來實現  
首先分析一下三種模板  
1. 若是最基本的，只想要找到target的idx  
因為我們把right初始化為`arr.size() - 1` ，所以**搜索區間**是`[left, right]`  
因此while裡面應該是`(left <= right)`，子區間也是左閉右閉，所以應該是`left = mid + 1`和`right = mid - 1`  
因為只要找到target的idx即可，所以相等立刻return
2. target有複數個，想要尋找左側邊界  
因為我們把right初始化為`arr.size()`，所以**搜索區間**是`[left, right)`  
因此while裡面應該是`(left < right)`，子區間也是左閉右開。檢查完`mid`後，左區間應該是`[left, mid)`，而右區間是`[mid + 1, right)`。  
因為要找到左側邊界，所以就算找到target也不要立刻return，而是繼續左移right來找到左側邊界  
3. target有複數個，想要尋找右側邊界  
因為我們把right初始化`arr.size()`，所以**搜索區間**是`[left, right)`  
因此while裡面應該是`(left < right)`，子區間也是左閉右開，所以應該是`left = mid + 1`和`right = mid`  
因為要找到右側邊界，所以就算找到target也不要立刻return，而是繼續右移left來找到右側邊界  

> 原來究竟要選(mid + 1)還是(mid)完全是由區間的樣子決定呀！while(left < right)區間為左閉右開的情況下，子區間也必定會是左閉右開。我們檢查完mid上的元素之後，改變的搜索區間不需要再檢查一次mid，因此子區間會變成[left, mid - 1.....)mid.....[mid + 1, right)

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
-> 同向雙指針  
* [lintcode 1375](./lintcode/lintcode1375.cpp)  
* [leetcode 3](./leetcode/leetcode3.cpp)
* [leetcode 340](./leetcode/leetcode340.cpp)
* [leetcode 76](./leetcode/leetcode76.cpp)
* [leetcode 475(比較不明顯的雙指針)](./leetcode/leetcode475.cpp)
* [lintcode 194](./lintcode/lintcode194.cpp)
* [lintcode 404 三指針](./lintcode/lintcode404.cpp)
* [lintcode 1879 看似沒有單調性的變態](./lintcode/lintcode1879.cpp)
* [lintcode 390](./lintcode/lintcode390.cpp)

參考下面模板：  
```cpp
// 我們把引路的指針比喻成教主，被引路的比喻成信徒好了
while 教主還沒走完路
    while satisfied-condition && 信徒還沒走完
        信徒繼續走
```
上面想辦法維持了信徒與教主最近並且符合condition的距離。記住，教主跟信徒不同時動也不交錯，因此能得出`O(n)`的結果。  

-> 滑動窗口 sliding window
* [lintcode1849 經典題](./lintcode/lintcode1849.cpp)
* [lintcode1850 隔板法](./lintcode/lintcode1850.cpp)

sliding window通常會先用`O(window-size)`算出初始化的window sum。接下來每往右移一步都只需要考慮最左邊和最右邊的變化就好！  

上面sliding window中有一種配合隔板法的變化題，通常會在同一個數組要求兩個不重合區間的最優解(interval sum之類的)。我們可以列舉隔板將數組分裂成兩塊，那就變成在兩塊中個別求sliding window。目前用起來雖然時間複雜度不是最好，但是思路最清晰！

> O(n)可以先想雙指針，因為兩個指針不會交錯(因此條件為left <= right)。這樣整個n只會跑一次！

> 同向雙指針的題目上若要思考是right先動還是left先動，從題目要的答案上去思考！目前偷偷看出兩個規律，一個是如果找最短結果，我們會在一個地方固定right，開始向右移動left來縮短範圍。而如果是找最長結果，那我們會先固定好left，然後把right往右推到符合條件的位置並且擴大範圍。

### BFS
* [...leetcode 200 traverse](./leetcode/leetcode200.cpp)
* [lintcode 630 shortest path](./lintcode/lintcode630.cpp)
* [leetcode 269 經典topo題](./leetcode/leetcode269.cpp)
* [lintcode 1364 傳送門](./lintcode/lintcode1364.cpp)
* [lintcode 1565](./lintcode/lintcode1565.cpp)
* [leetcode 200](./leetcode/leetcode200.cpp)
* [lintcode 677](./lintcode/lintcode677.cpp)
* [lintcode 598](./lintcode/lintcode598.cpp)
* [lintcode 1422 visited紀錄的是整個圖的狀態 (狀壓binary)](./lintcode/lintcode1422.cpp)
* [lintcode 941 visited紀錄的是整張圖的狀態 (狀壓str)](./lintcode/lintcode941.cpp)
* [lintcode 573](./lintcode/lintcode573.cpp)
* [lintcode 1828](./lintcode/lintcode1828.cpp)

time complexity: `O(n)`  
space complexity: `O(n)`  

queue：先進先出  

不分層：  
```cpp
queue<T> q;
unordered_set<T> visited;

q.push(root);
visited.insert(root);
while(!q.empty()) {
	const T &head = q.front();
	// 這裡就可以進行一些對當前點的處理
	// e.g. 檢測是不是到終點了？
	q.pop();
	for(const T &neighbor : head.neighbor) {
		if(!visited.count(neighbor)) {
			// 這裏visited和queue都要一起加，root的部分已經在上面加過了
			// 在點入queue的時候加入visited，check valid，和update distance
			visited.insert(neighbor);
			q.push(neighbor);
		}
	}
}
```
分層：  
```cpp
// ...的部分都是一樣的
// 只是我們事先用queue的大小限制住一次expand的數量
// queue也就是當前level的neighbor數量
...
while(...) {
	int sz = q.size();
	for(int i = 0; i < sz; i++) {    // 只有這裡不一樣
		const T &head = q.front();
		...
		for(...) {
			...
		}
	}
}
``` 

拓墣 用於有向無環圖，我們可以用它來判斷圖裡有沒有環，如果有那traverse也會失敗。拓墣排序還常拿來判斷兩個點之間有沒有路線，但這樣用 disjoint set 更快更簡潔。  
1. 統計所有點的in-degree
2. 將那些in-degree為0的點(我們稱作沒有依賴)放入queue
3. 從queue裡面pop出來，並且訪問每一個pop出來的點的所有鄰居，然後把這些鄰居的in-degree都-1
4. 如果某個鄰居的in-degree變成0，就把他放入queue中
5. 直到queue為空

```cpp
/*
 * @param graph: A list of Directed graph node
 * @return node: Any topological order for the given graph.
 */
vector<DAG*> node;
unordered_map<DAG*, int> n;   // in-degree
queue<DAG*> q;
for(auto nd : graph) {
	for(auto i : nd->neighbors) {
		n[i]++;
	}
}
for(auto nd : graph) {
	if(n[nd] == 0)
		q.push(nd);
}
while(!q.empty()) {
	DAG* head = q.front();
	q.pop();
	node.push_back(head);
	for(auto neighbor : head->neighbors) {
		if(--n[neighbor] == 0)
			q.push(neighbor);
	}
}
return node;
```
要怎麼判斷是否有環。如果最後`node`的長度不等於節點數，就代表中間有環！

> 求**最短路徑**，最少次數: 優先想到bfs  

> 遍歷**搜索**，或按層遍歷，拓墣  

> 指數級別用雙向BFS優化 e.g. 2^2n => 2^n + 2^n 知道思路就行:)  

> 靜態圖用BFS，實時修改的圖用union find  

> 萬一在找出最短路徑後，他又叫我們輸出最短路徑，我們可以用資料結構去存每個node的parent node e.g. last_point[node2] = node1。這邊注意一下，我們不會去存下一個node，因為每個node的下一個node可以有幾種選擇，但是上一個node通常只有一個選擇！

> 感覺topo幾乎用在不知道起點是哪裡，想要透過neighbor的關係理出整張圖的路線。而bfs用在已經知道起點在哪，求到終點的最短路線...etc。

> 什麼時候用level order呢？level order是用解決計算步伐的問題。其實就是代表每一次只能走一步，所以如果是算最短路徑的題目，我們想用每一層distance++來計算最終路徑，不用level order是不行的！不分層的bfs基本上用在算兩點是否相通而已... 另外一招便是把visited數組直接改distance數組，我們就不用擔心每一次到底是加幾步的問題了: e.g. lintcode 1565裡的dist數組

> 值得注意的是多出發點類型的地圖問題：來比較一下 lintcode-677 和 lintcode-598 的處理方式。可以發現677中，我們邊用for迴圈遍歷地圖，邊在找到的出發點上進行bfs; 可是在598中，我們就分開動作，直接遍歷完整個地圖把出發點放入queue中，然後再進行bfs。兩個題目的不同處在於後者的map會不斷變動，也就是說出發點會不斷變動。為了在bfs上避免這個問題，才會有後者這種應對方式！

> 為何多出發點類型的問題中，先找到的路徑就一定是最短路徑呢？記住！我們並不是把一條路徑完成才去遍歷下一條，仔細看BFS的結構，他的while loop是在每一條路徑上各踏一步下去進行的，因此比較短的路徑當然會先完成，就可以先return囉！

> 關於visited的思路：代表訪問過的不再訪問。但，對象未必是點，也可能是狀態。常見的hard題型常常把題圖狀態壓縮放到visited之中，通常這種時候input size都會特別小，可以用二進位或者是string的方式把地圖壓縮成一維！

### 樹上問題
#### BFS

> 求樹上最大直徑

思路：請參考[下面comment](./lintcode/lintcode291.cpp)  
兩次BFS：第一次由任一點出發找最遠的點t1，第二次由t1出發找最遠的點，第二次得到的最大距離就是解！  
Follow up求第二路徑: 破壞我們的第一直徑。非由兩個端點一起構成的路徑中最大的，就是第二直徑！  

* [lintcode 1469](./lintcode/lintcode1469.cpp)
* [lintcode 291](./lintcode/lintcode291.cpp)

#### DFS
binary tree題型的話有很高機率用dfs做，將答案切分成左子樹和右子樹(divide and conquer)。  
binary tree上的DFS可以分成求值(e.g. 路徑，極值)或修改tree架構(e.g. 請把tree改成鏈表)兩種類型。  
遞歸的思想真的很不直觀  
tree的問題不用把左右子樹分開想，兩個孩子要做的事情是一樣的  
return value通常是父親想從兒子那邊獲得的訊息，從這個角度去著手  
有趣的是，最終答案也不會是這個dfs的return value，return value只是一個傳送訊息的媒介，我們的答案在於divide之後conquer的資訊!  

### DFS
DFS就是將**backtracking**用在樹型的資料結構上  
只需要思考三個問題：  
1. 做過的選擇
2. 當前可選的選擇
3. 終止條件  
```cpp
vector<T> res;
void backtrack(saved choice, curr choice) {
    if(終止條件) {
        res.push_back(saved choice)
        return
    }

    for(auto choice in curr choice) {
        make choice
        backtrack(saved choice, curr choice)
        reset choice
    }
}
```
* [leetcode 46 排列(無重複) backtrack + 用visited排除已經選過的](./leetcode/leetcode46.cpp)
* [leetcode 47 排列(有重複) 選代表](./leetcode/leetcode47.cpp)
* [leetcode 51 N Queens 加上撇和捺的visited即可](./leetcode/leetcode51.cpp)
* [leetcode 78 子集(無重複) backtrack + 用start idx排除已經選過的](./leetcode/leetcode78.cpp)
* [leetcode 77 組合 backtrack + start idx](./leetcode/leetcode77.cpp)
* [leetcode 22 生成合法括號 左括號數 >= 右括號數](./leetcode/leetcode22.cpp)
* [leetcode 543 binary tree](./leetcode/leetcode543.cpp)
* [leetcode 124 binary tree max path sum](./leetcode/leetcode124.cpp)
* [lintcode 262 heir tree](./lintcode/lintcode262.cpp)
* [lintcode 582 wordbreak II 列出所有方案](./lintcode/lintcode582.cpp)

:star: Trajan's algorithm  
critical connection的定義是指如果把該edge拆除，將會影響到網路中某些節點不能連結。要找出這種edge，Trajan的想法是找出**非環中**的edge！每一次dfs traversal紀錄下當前節點所能訪問到的最小深度，若回傳的深度比當前節點還深則代表**非環**！  
* [lintcode 1271 Critical Connections in network](./lintcode/lintcode1271.cpp)

time complexity: `O(方案總數 * 每個方案的時間)`  

### 動態規劃
動態規劃的核心無非是dfs + memo然後可以轉換成數組的型態  
區別就在於dfs是由頂向下，而dp是由底向上  
第一步：確認**狀態**  
第二步：dp數組/函數的定義(可以一維表示一個狀態)，其實這裡很看套路  
第三步：確認**選擇**，實現狀態轉移  
第四步：coding邊處理邊界狀況(base case)吧  

時間複雜度分析：子問題數(狀態組合數量) * 子問題解決的時間複查度  

要使用dp有一個相當重要的條件：子問題之間必須獨立  

關鍵字：  
方案總數/極值/可行性  

數組遍歷方向：  
有時正向，有時反向，有時斜向，有時甚至皆可  
那麼怎麼判斷呢？  
只要記得**遍歷的過程，我們所需的狀態一定要先算出來**  
並且**遍歷的終點，就是我們的答案**  

狀態壓縮：  
`dp[i][j]`都只依賴相鄰的狀態  
把二維投影進一維  
要怎麼重新處理狀態轉移呢？  
思考原本轉移方程中狀態對應到二維中的什麼位置  
壓縮到一維後會不會被覆蓋掉  
可以用變量保存或者改變遍歷順序就好  
[揭開DP狀態壓縮的神秘面紗](https://blog.1pwnch.com/posts/dp-optimize/)  
通常對角線遍歷不好寫，可以用由下往上取代！  

子序列型 and 子數組型dp：  
subsequence的問題比subarray的問題還要困難，因為subsequence是不連續的，要列舉所有的可能性就需要指數級別的時間。所以基本上`subsequence + 求極值`一定是用動態規劃！  
subsequence的問題離不開這兩種定義模板：  
```cpp
dp[i]: 代表以array[i]作結的子序列
dp[i][j]:
若有兩個字串或數組的話，
代表arr1[0...i]和arr2[0...j]的關係為dp[i][j]
arr1前i個和arr2前j個的關係為dp[i][j]
若只有一個字串或數組，代表arr[i...j]為dp[i][j]
```
* [leetcode 516](./leetcode/leetcode516.cpp)
* ([回文substring的話請參考leetcode 5](./leetcode/leetcode5.cpp))
* [leetcode 256](./leetcode/leetcode256.cpp)
* [leetcode 72](./leetcode/leetcode72.cpp)
* [leetcode 300 (Longest Increasing Subsequence) (+ binary search)](./leetcode/leetcode300.cpp)
* [leetcode 354 (Longest Increasing Subsequence變種)](./leetcode/leetcode354.cpp)
* [leetcode 1143 (Longest Common Subsequence)](./leetcode/leetcode1143.cpp)
* [leetcode 583 (拐著彎叫你求LCS)](./leetcode/leetcode583.cpp)
* [leetcode 712 (求最大ASCII sum的 LCS)](./leetcode/leetcode712.cpp)

> LIS可以用patience sorting解，時間複雜度對數級別

劃分型dp：  
* [leetcode 139 word break](./leetcode/leetcode139.cpp)
* [lintcode 512 decode ways](./lintcode/lintcode512.cpp)
* [lintcode 676 decode ways II](./lintcode/lintcode676.cpp)

> dp[i]代表前i個的部分是否可行

> 前綴型的dp

> 比較沒感覺:)

區間型dp要注意：  
把區間分割後如果用枚舉的來求解，可能後區間的答案前面還沒算過  
可以用長度之類有順序性的方式來枚舉  
(不過其實區間型的目前大概就stone game和burst balloon而已...)  
* [lintcode 476/593 stone game](./lintcode/lintcode476-593.cpp)  
* [leetcode 312 戳氣球](./leetcode/leetcode312.cpp)  

> 區間型dp最有名的優化方式：用四邊形不等式優化枚舉切割點的時間

> 區間型dp常見的定義是dp[i][j] = dp[i][k] + dp[k + 1][j]，也就是更小區間的最優解。不過就要注意，在運算dp陣列時k不能用枚舉的，因為後面的區間結果我們根本還沒有！取而代之，可以用長度枚舉。  

博弈型dp：  
這類問題都是兩個人交替進行選擇  
難點在於先手會影響後手的結果  
套路通常就是使用二維dp，然後裡面在個別存先手和後手的結果(e.g. `pair<int, int>(first, second)`)  
上面的first和second個別代表先手後手使用決策所得到的最優結果  
* [leetcode 877 石子遊戲](./leetcode/leetcode877.cpp)  

背包問題：  
狀態： 背包的容量, 可選擇的物品  
選擇： 物品放進背包/不放  
思路：  
可以塞滿代表(n - 1)個東西時就能塞滿或是n個東西剛好能塞滿？  
背包問題有很高的機會可以進行狀態壓縮喔！  
* [lintcode 92 背包問題(物品沒有價值的版本)](./lintcode/lintcode92.cpp)
* [lintcode 563 0/1背包問題](./lintcode/lintcode563.cpp)  

背包問題的變形：  
* [leetcode 416 背包問題](./leetcode/leetcode416.cpp)

完全背包問題(物品數量無限)：  
* [leetcode 518](./leetcode/leetcode518.cpp)
* [lintcode 440](./lintcode/lintcode440.cpp)

概率型dp:  
求概率  
* [lintcode 20](./lintcode/lintcode20.cpp)

股票問題：  
思路: 狀態機，列舉出狀態和相應的選擇  
狀態有三種：天數，當天允許交易的最大次數，目前持有狀態  
選擇有三種：buy, sell, rest  
```
先列轉移方程：
昨天就持有，或今天買的
dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
昨天就沒有，或今天賣掉的
dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);

根據out of bound的case思考base case：
根本還沒開始交易
dp[-1][k][0] = 0
還沒開始交易，哪來的利潤，用負無窮表示
dp[-1][k][1] = INT_MIN
k是從1開始的
k為0的情況代表還沒開始交易
dp[i][0][0] = 0
dp[i][0][1] = INT_MIN

轉移方程裡：k很少次(可以直接列舉)，或是無限的情況，甚至都不需要k這個dimension了
```
* [lintcode 149 交易一次](./lintcode/lintcode149.cpp)
* [lintcode 150 交易次數無限](./lintcode/lintcode150.cpp)
* [lintcode 995 交易無限 + cooldown一天](./lintcode/lintcode995.cpp)
* [lintcode 1000 有手續費喔！](./lintcode/lintcode1000.cpp)
* [lintcode 151 交易兩次](./lintcode/lintcode151.cpp)
* [lintcode 393 k次交易 內存爆炸怎麼解決](./lintcode/lintcode393.cpp)

正則表達式問題：  
* [leetcode 10 另外分析'*'的情況](./leetcode/leetcode10.cpp)

丟雞蛋問題(當然丟什麼都行)：  
* [leetcode 887](./leetcode/leetcode887.cpp)  

打家劫舍問題(House Robber)：  
* [leetcode 198 House Robber](./leetcode/leetcode198.cpp)
* [leetcode 213 House Robber + 房子繞成一圈](./leetcode/leetcode213.cpp)
* [leetcode 337 House Robber + 房子二叉樹](./leetcode/leetcode337.cpp)

> DP是用來將指數時間和階層時間的問題優化成O(n^2), O(n^3)的。如果問題本來就可以在更短的時間內解決，那代表dp是不適用的方法

> DP數組跟遞歸就只有一線之隔。差距在於DP數組由底向上求解(問題規模由小到大)，遞歸由頂向下求解(問題規模由大而小)

> 常常疑惑為何dp數組要這樣定義呢？是為了狀態轉移。找狀態轉移需要歸納思維，也就是從已知的結果推斷未知的部分。

> 不知道要怎麼決定遍歷方向時，把圖畫出來看更新狀態所需的已知狀態在哪兒，就能理解要怎麼遍歷了

### 貪心問題
每一次都選局部最優，最後就能得到全局最優的答案  
* [leetcode 435 無重疊區間問題](./leetcode/leetcode435.cpp)
* [leetcode 452 轉換成計算重疊區間問題](./leetcode/leetcode452.cpp)
* [leetcode 55 Jump Game](./leetcode/leetcode55.cpp)
* [leetcode 45 Jump Game II (DP會TLE)](./leetcode/leetcode45.cpp)

### 並查集Union find
* [leetcode 261](./leetcode/leetcode261.cpp)  
* [leetcode 547](./leetcode/leetcode547.cpp)
* [leetcode 721 經典必練題](./leetcode/leetcode721.cpp)
* [lintcode 261](./lintcode/lintcode261.cpp)

其實union find的模板很固定：  
```cpp
private:
    vector<int> father;
    int count;
    int find(int x) {
        if(father[x] == x)
            return x;
        // path compression
        return father[x] = find(father[x]);
    }
    
    void connect(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if(fx != fy) {
            father[fx] = fy;
            count--;
        }
    }
```
這裏先創一個`father`數組，裡面維護的是每一個node的father  
另外維護了一個count作為連通塊的數量  
`find(路徑壓縮)`: 上面的find用於尋找最上面的祖先。路徑壓縮非常有用，會把x到root路徑上所有的點直接改成`x->root`。這樣的優點是若原本很長的鏈`x->y->z....->root`，會被我們壓縮成`x->root`/`y->root`/`z->root`。查詢的時間複雜度由`O(n)`壓縮成`O(1)`。  
`connect(連結點)`:都**先找到最上面的祖先**，把他們串在一起。每一次merge會讓連通塊的數量減1。  

> 注意father[]一開始初始化可以為自己，也可以為null。差別在於find中loop的終止條件不一樣！

> 題目的node若為數字那我們用vector<int>存就好。如果是str之類型態，我們換成hashmap就好。

> union find可以應用於MST的生成。union find的connect不會導致circle，因為他會先透過find查詢兩個點是否已經在同一個集合。

> 要回傳一個點的root，一律用find(x)，用father[x]會錯。因為connect裡面並沒有繼續做路徑壓縮

### MST
MST就是最小的connected graph，一個可以到所有的點的子圖。minimum則是路徑cost的最小總和。因此MST可能不是唯一的！  

Kruskal演算法流程：  
1. 先按照cost將所有edges由小排到大
2. 把所有的edge拆掉只剩下nodes。按照之前排序的順序放上圖，如果出現環就不加入edge，若否，則connect後更新cost sum
3. iterate一遍後，檢查是否為n-1個邊。畢竟樹就是n-1條邊。

> Kruskal很適合sparse graph，因為前面需要對所有edge排序。

> 上面的node連結直接用union find實現即可。因為union find的connect不會導致circle

### 字典樹 Trie
* [Lintcode 333](./lintcode/lintcode333.cpp)


優點在於查詢**公共prefix**  
字母存在edges上，單字存在node上  
每個node存了兩個attribute：`bool isword`, `string word`  
在看模板之前先來弄清楚一些字典樹的小特性：  
> 字典樹所有單字都是從root開始算起  

> 字典樹的高度是最長單字的長度 + 1  

好了。來上個模板吧...  
```cpp
class TrieNode {
public:
    TrieNode *next[26];
    bool isword;
    TrieNode() {
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
        isword = false;
    }
};
class Trie {
private:
    TrieNode *root;
public:
    /** Init */
    Trie() {
        root = new TrieNode();
    }
    /** 將所有的單字輸入建立字典樹 */
    // 若下個node為null，代表還為插入字母
    // new 一個 TrieNode
    void insert(string word) {
        TrieNode *p = root;
        for(int i = 0; i < word.length(); i++) {
            if(p->next[word[i] - 'a'] == NULL) {
                p->next[word[i] - 'a'] = new TrieNode();
            }
            p = p->next[word[i] - 'a'];
        }
        p->isword = true;
    }
    /** 樹中是否存在word呢？ */
    // 我們沒有代表edge的屬性，有的是node
    // 因此我們會先把 ptr 指到下一個node，藉此來連上edge
    bool search(string word) {
        TrieNode *p = root;
        for(int i = 0; i < word.length(); i++) {
            p = p->next[word[i] - 'a'];
            if(p == NULL)
                return false;
        }
        // 注意我們最後回傳的是isword
        // 儘管字典樹中存在這個word，但traverse到當前有可能僅僅是個prefix，而非word
        return p->isword;
    }
    /** 樹中是否有單字是以prefix為前綴的呢？ */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for(int i = 0; i < prefix.length(); i++) {
            p = p->next[prefix[i] - 'a'];
            if(p == NULL)
                return false;
        }
        // 理念跟上面大致相同
        // 但prefix就不需要為單字囉！
        return true;
    }
};
```
簡單分析一下：除了題目原本的Trie class，我還另外創立了TrieNode這個class。TrieNode這個class有兩種屬性：1. 指到下一個node(`next`)。還記得Trie會把字母存在edge上嗎？26種字母代表指到下一條路徑有26種方法，用大小為26的陣列來代表即可。2. `isword`：從root traverse到當前TrieNode的路徑所拼接起來的字串，若為單字則為`true`。注意我們將其初始化為`null`。並非只是因為設計理念，其中還有包括初始化為`new TrieNode()`會造成死循環的原因。以上操作時間複雜度都為`O(L)`，L為字的長度。  

### 位運算技巧
可以用位運算來加速時間複雜度因為電腦對十進位數字進行運算還要另外轉換成二進位。像是N-Queen公認最快的解法便是位運算的！  
* [cxyxiaowu bit operation LC problem](https://www.cxyxiaowu.com/8990.html)  
* [BitwiseOperators](https://wiki.python.org/moin/BitwiseOperators)
* [Basics: how to convert negative decimal to binary](https://superuser.com/questions/975684/converting-negative-decimal-to-binary)
* [Basics: What is Bit Masking?](https://stackoverflow.com/questions/10493411/what-is-bit-masking)
* [bit operation](https://oi-wiki.org/math/bit/)

## 單調
* [Leetcode 239 - mono deque](./leetcode/Leetcode239.cpp)
* [leetcode 862 - mono deque](./leetcode/leetcode862.cpp)
* [leetcode 621 - mono deque](./lintcode/lintcode621.cpp)

> 這裡使用mono deque的題型有很大的概率都是為了維護sliding window或interval中的極值/總和，使用deque可以高效率的從隊首彈出，從隊尾為了維護單調性而彈出然後插入新元素。