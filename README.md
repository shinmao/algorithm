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
        return mid;\
    if(nums[mid] < target)
        start = mid;
    else
        end = mid;
}
if(nums[start] == target)
    return start;
if(nums[end] == target)
    return end;
```

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

> 值得注意的是多原點類型的地圖問題：來比較一下 lintcode-677 和 lintcode-598 的處理方式。可以發現677中，我們邊用for迴圈遍歷地圖，邊在找到的出發點上進行bfs; 可是在598中，我們就分開動作，直接遍歷完整個地圖把出發點放入queue中，然後再進行bfs。兩個題目的不同處在於後者的map會不斷變動，也就是說出發點會不斷變動。為了在bfs上避免這個問題，才會有後者這種應對方式！

### DFS
* [leetcode 543 binary tree](./leetcode/leetcode543.cpp)
* [leetcode 124 binary tree max path sum](./leetcode/leetcode124.cpp)
* [lintcode 262 heir tree](./lintcode/lintcode262.cpp)

在經典問題subset/permutation中，有兩種實現方式：一是在每一層選擇加/不加，二則是backtrack。Backtrack的方式非常適合用來做排列。  
第一種方式的話，要加入dfs出口條件：當(加/不加)決定通過了最後一個元素，就可以打包行李走人囉！  
第二種方式的話，不需要加入出口條件：因為我們用for迴圈循環加入元素時，迴圈就有個上限了！  
解決重複元素的問題(搭配backtrack)：選代表(通常我們會選第一個最方便)，然後用`index`與`start-index`判斷是否為重複元素中的第一個(注意！這裡就跟上面不一樣，一定要sort喔，不然重複的元素會無法擠到一起)  
解決排列元素的問題(搭配backtrack)：每一次都從整個陣列遍歷一遍，因此不需要一個`start-index`。使用`visited`陣列來判斷元素有沒有被加入到子陣列中。出口條件便是：如果我們的子陣列還沒有加入原陣列所有元素，就要繼續遍歷下去！  

binary tree題型的話有很高機率用dfs做，將答案切分成左子樹和右子樹(divide and conquer)。  
binary tree上的DFS可以分成求值(e.g. 路徑，極值)或修改tree架構(e.g. 請把tree改成鏈表)兩種類型。  
遞歸的思想真的很不直觀  
tree的問題不用把左右子樹分開想，兩個孩子要做的事情是一樣的  
return value通常是父親想從兒子那邊獲得的訊息，從這個角度去著手  
有趣的是，最終答案也不會是這個dfs的return value，return value只是一個傳送訊息的媒介，我們的答案在於divide之後conquer的資訊!  

樹還有一種題目是用DP下去做的喔，也就是父節點的資訊可以由子結點彙整就好，詳細情況看下面DP的部分唄...  

在寫每一層的內容時，盡量只想著當前這層，在callback時再思考與其他層的關係

dfs backtrack竅門:  
```cpp
opertaion 1
dfs()
operation 2
```
operation 2 必須把 operation 1 的影響還原回來  

> 一般求所有方案的題目可以往dfs方向想

> 如果還是爆棧了，唉還是用看看BFS唄

### 動態規劃
* [leetcode 256](./leetcode/leetcode256.cpp)
* [leetcode 416 背包問題](./leetcode/leetcode416.cpp)

區間型dp要注意：  
把區間分割後如果用枚舉的來求解，可能後區間的答案前面還沒算過  
可以用長度之類有順序性的方式來枚舉  
(不過其實區間型的目前大概就stone game和burst balloon而已...)  
* [lintcode 476/593 stone game](./lintcode/lintcode476-593.cpp)  

> 區間型dp最有名的優化方式：用四邊形不等式優化枚舉切割點的時間


雖然用數組先把答案存起來像dp，但沒有順序性，單存由dfs traverse的memoi類型：  
* [leetcode 337 樹上dp](./leetcode/leetcode337.cpp)  
* [正則...]()  
* [word break...]()   


-> 子問題 而且 只解決一次  
-> 子問題的答案用資料結構存起來

1. 確定狀態：可以從最後一步，最後的答案推測  
第n個的話，他跟n-1的關係是啥？  
2. 子問題
3. 轉移方程：要注意初始條件和邊界

背包問題：  
背包大小為m，我行李中有些東西想放進去，有沒有機會塞滿滿？  
思路：  
可以塞滿代表(n - 1)個東西時就能塞滿或是n個東西剛好能塞滿？  
背包問題有很高的機會可以加以優化呦！  

> DP是用來將指數時間和階層時間的問題優化成O(n^2), O(n^3)的。如果問題本來就可以在更短的時間內解決，那代表dp是不適用的方法

> DP空間常常可以優化，如果發現之前的資訊其實不需要了，可以用變數來代替就好

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