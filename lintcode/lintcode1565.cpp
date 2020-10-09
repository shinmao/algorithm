// 傳送門的解法這裡就不再詳述
// 這裡最重要是dist數組
// 照理來說原本要用queue.size() 作 level ordered traversal
// 但要把dice和connection的distance分開算實在太麻煩了
// 所以這裡用dist數組取代這個麻煩
// dist數組會紀錄那個點的最短距離
// 而且也能夠直接當visited用
class Solution {
public:
    // start point: 1, end point: length
    int modernLudo(int length, vector<vector<int>> &connections) {
        queue<int> pos;
        vector<int> dist(length + 1, INT_MAX);
        pos.push(1);
        dist[1] = 0;
        while(!pos.empty()) {
            int head = pos.front();
            pos.pop();
            // with dice
            for(int i = 1; i < 7; i++) {
                // 這裡能夠直接當visited用
                // 畢竟如果沒用過dist一定還是INT_MAX
                if((dist[head + i] > dist[head] + 1)  && (head + i <= length)) {
                    dist[head + i] = dist[head] + 1;
                    pos.push(head + i);
                }
            }
            // with conn
            for(int conn = 0; conn < connections.size(); conn++) {
                if(head == connections[conn][0] && dist[head] < dist[connections[conn][1]]){
                    dist[connections[conn][1]] = dist[head];
                    pos.push(connections[conn][1]);
                }
            }
        }
        return dist[length];
    }
};