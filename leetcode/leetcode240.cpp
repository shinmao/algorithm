// 這個 O(m + n)的解法看似很簡單
// 但千萬要注意某些細節
// 你最剛開始只能從兩點出發: 右上角的點 和 左下角的點
// 你選到另外兩個點都會錯
// 我直接找 (0, 0) 來作解釋
// 我讓他小於 target 的時候一直加 row 或加 col 好了
// 那你大概就會一直待在同一行或同一列，最後也沒搜到答案孤老到死
// 不然我們選 (0, n - 1) 好了
// 我讓比他大的時候，增加 row / 比他小的時候，減少 col
// 這樣也絕對不會孤老到死！
// AC 81.32%
int m = matrix.size();
if(m == 0) return false;
int n = matrix[0].size();
if(n == 0) return false;

int row = m - 1, col = 0;
while(row > -1 && col < n) {
    if(matrix[row][col] == target) return true;
    if(matrix[row][col] < target) ++col;
    else --row;
}
return false;