// interesting trick
// i & (i-1) 是將最右邊的一位 1 轉換成 0
// 在 i > 0 的情況下，這樣操作 i 會變成 (i-1), (i-2), (i-4)...
// 差值都為一個 1 的 bit，因此都是 +1
// beats over 57% of submission
class Solution {
public:
    vector<int> countBits(int num) {
        int size = num + 1;
        vector<int> result(size, 0);

        for(int i = 1; i <= num; i++){
            result.at(i) = result.at(i & (i-1)) + 1; 
        }
        
        return result;
    }
};