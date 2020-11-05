class Solution {
public:
    /**
     * @param edge: edge[i][0] [1] [2]  start point,end point,value
     * @return: return the second diameter length of the tree
     */
    int bfs(int start, vector<vector<pair<int, long long>>> &path, vector<long long> &dist) {
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        
        while(!q.empty()) {
            int head = q.front();
            q.pop();
            for(auto it : path[head]) {
                int neighbor = it.first;
                long long len = it.second;
                if(dist[it.first] == -1) {
                    q.push(neighbor);
                    dist[neighbor] = dist[head] + len;
                }
            }
        }
        
        int node;
        long long max = -1;
        for(int i = 0; i < dist.size(); i++) {
            if(dist[i] > max) {
                max = dist[i];
                node = i;
            }
        }
        
        return node;
    } 
    
    long long getSecondDiameter(vector<vector<int>> &edge) {
        // write your code here
        int n = edge.size() + 1;
        
        vector<vector<pair<int, long long>>> path(n);
        for(auto it : edge) {
            path[it[0]].push_back(make_pair(it[1], it[2]));
            path[it[1]].push_back(make_pair(it[0], it[2]));
        }
        
        vector<long long> first_dist(n, -1);
        // bfs
        int t1_node = bfs(edge[0][0], path, first_dist);
        
        vector<long long> second_dist(n, -1);
        int t2_node = bfs(t1_node, path, second_dist);
        
        // t1_node -> t2_node is the first diameter
        vector<long long> third_dist(n, -1);
        int t3_node = bfs(t2_node, path, third_dist);
        // but we don't need t3_node because it must be equal to t1_node :)
        
        long long res = 0;
        for(int i = 0; i < n; i++) {
            // from t2_node
            if(i != t1_node)
                res = max(res, third_dist[i]);
        }
            
        for(int i = 0; i < n; i++) {
            // from t1_node
            if(i != t2_node)
                res = max(res, second_dist[i]);
        }
        
        return res;
    }
};
/**
首先，注意这里的“树”是图论的概念，和二叉树中的链表结构不是一回事。
“树”的定义是：没有回路的连通图。在这样的图中，你可以以任意一个节点看做是“根”，然后把“根”拎起来，想象其他节点“自然垂下”，就是一棵树的形态。

我们先解决这样一个子问题：如何在一棵树里面找到最大的直径，也就是两两点对之间距离的最大值。
LeetCode 1245 Tree Diameter

这是图论里面的经典问题，有着一个很成熟的经典解法：

以图里的任意一个节点作为起始点A（看做根），往外做BFS遍历，能够到达的最远的节点B，那么B一定是最大直径的一个端点。
我们以B作为起始点（看做根），往外做BFS遍历，能够到达的最远的节点C，那么BC的路径就是最大直径的距离。
我们给个简单的证明：从任意点A开始，能够到达的最远的距离是B。另外，整张图里“最长的点到点距离”是S和T。
我们要证明B只可能是S或者T中的一点。如果不是，那么分情况讨论：

(1) AB与ST完全不相交。

 A ----- B
     |
 S --X-- T
那么我们从A找一条路径能够到达ST的路径，并令交点是X。因为AB是从A起始的最长路径，那么AB>AX+XT.
那么我们观察路径B->A->X->S，其距离BA+AX+XS > 2AX+XT+XS > 2AX+ST > ST，这就与ST是全局“最长的点到点距离”矛盾。

(2) AB与ST相交于X。

     A 
     |
 S ==X== T
     |
     B
因为AB是从A起始的最长路径，那么AX+XB>AX+XS，即XB>XS.
我们观察路径B->X->T，其距离BX+XT > XS+XT = ST，这就与ST是全局“最长的点到点距离”矛盾。

(3) 还有一些corner cases，比如说B就在ST的路径上等等。都容易结合图形分析。

综上，我们的子问题的算法就得到了理论上的证明。而BFS的实现也是非常简单的。

接下来，我们来看本题的要求：求这棵树的第二直径。
通常这类问题有个比较自然的思路，就是破坏掉第一直径，那么你在剩下的图里能得到的最大直径，就是之前的第二直径。
那么本题中如何破坏呢？因为最大直径ST的两个端点都必然是叶子节点，所以我们either remove S or remove T，就能破坏掉最大直径的路径，同时不影响其他任何路径。

OK，假设我们remove S，那么如何找到接下来的最大直径呢？我们的结论是：此时的最大直径，一定是会以T为端点。
这是为什么呢？这可以利用之前的结论。在破坏S之前，有一部分点作为起始能够BFS达到的最远端点是S，另外一部分点作为起始能够BFS达到的最远端点是T。
当我们remove S之后，肯定依然还有一部分点作为起始能够BFS达到的最远端点是T。（这是因为S只是一个叶子节点）。
根据之前证明的引理，那么T一定就是在remove S之后，剩下的图的最大直径的一个端点。
那么我们只需要只需要以T为起始点，再次BFS，找到最远的端点距离，那么就是此时的最大直径长度。

同理，我们也要remove T，来看以S为起始点再次BFS，能找到最远的端点距离。

所以看上去总共是4次BFS，分别是：

以任意点开始BFS，得到最远的点S；
以S点开始BFS，得到最远的点T；于是ST就是最大直径。
以S点开始BFS，除去T点外，能得到的最远距离d1。
以T点开始BFS，除去S点外，能得到的最远距离d2。
答案就是max(d1,d2)
其中2和3的BFS其实是重复的。实际只需要三次BFS即可。
**/