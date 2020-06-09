// first solution:
// enumerate head and tail point, height would be the minimum number between head and tail
// Brute Force
// beats only 5%
class Solution {
    public int largestRectangleArea(int[] heights) {
        if(heights == null || heights.length == 0) return 0;
        
        int area = 0;
        for(int head = 0; head < heights.length; head++){
            int min_height = heights[head];
            for(int tail = head; tail < heights.length; tail++){
                if(heights[tail] < min_height){
                    min_height = heights[tail];
                }
                area = Math.max(area, (tail-head+1) * min_height);
            }
        }
        
        return area;
    }
}

// second solution:
// 目前看起來最簡潔的解法: monotonic stack
// 對於每個高度
// 面積最大都到左右兩邊第一個比他矮的界線前為止 left bound, right bound
// 所以轉換問題: 當前的數要怎麼找到左右第一個比他小的數?
// 關於monotonic stack，是用來維護ascending order或descending order，會把破壞順序的element給pop掉
// 此題的例子是要做一個monotonic ascending stack，因為只要高度繼續上升，長方形就可以繼續向右延伸，相反的就會變成bound而停止
// 為什麼是 i <= heights.length 而不是 i < heights.length呢?
// 在 = heights.length以前，是在計算那些不是bound的長條的最大面積
// 在 = heights.length之時，則是在計算那些還在stack中的bound的長條所可以得到的最大面積
// 每個element最多都只會進出stack n 次，因此時間複雜度是線性的
// beats over 27% of submission
// 推薦閱讀wp: https://yuanfanz.gitbooks.io/padawan-algorithm/dan-diao-zhan-one-dick-stack.html
class Solution {
    public int largestRectangleArea(int[] heights) {
        if(heights == null || heights.length == 0) return 0;
        
        int max = 0;
        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i <= heights.length; i++){
            int cur = (i == heights.length ? -1 : heights[i]);
            // 注意這邊用 < 比較好
            while(!stack.isEmpty() && cur < heights[stack.peek()]){
                // get the right bound
                int height = heights[stack.pop()];
                // stack peek would be left bound
                // 只有right bound，沒有left bound，可以把left bound想作-1
                int width = (stack.isEmpty() ? i : i - stack.peek() - 1);
                max = Math.max(max, height*width);
            }
            stack.push(i);
        }
        return max;
    }
}

// 另外注意: 有一種思維會引發錯誤
// 留在stack中最後的elements為可能的left, right bound
// 因此只要留意left right bound作為寬，這個範圍內最低的高 即為最大的長方形
// 但是這個想法是錯的!
// 舉個栗子 [2, 1, 5, 100, 2, 3]
// 最後留在stack裡的element為[1,2,3] 而left 為1 right為2的範圍中最低的高度為5，長方形面積為5*2
// 卻還是遠遠不及100這單個長條的面積
// 由此可知，我們還是必須由每個高度下去找left and right bnd來得到最大面積