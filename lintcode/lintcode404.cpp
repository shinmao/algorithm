// 這題剛開始我用prefix sum作
// 然後列舉每個區間來查詢，結果發現會TLE
// 後來用三指針解：左指針固定，右二指針找尋bound
int subarraySumII(vector<int> &A, int start, int end) {
    int n = A.size();
    int count = 0;
    // R為右開區間
    int left = 0, minR = 0, maxR = 0;
    int minSum = 0, maxSum = 0;
    
    while(left < n) {
        // 有可能會有left > right的情況
        // 也就是right遲遲未行動
        // 這種情況下我們要讓right至少行動到left的位置
        minR = max(minR, left);
        maxR = max(maxR, left);
        while(minR < n && minSum + A[minR] < start) {
            minSum += A[minR];
            minR++;
        }
        while(maxR < n && maxSum + A[maxR] <= end) {
            maxSum += A[maxR];
            maxR++;
        }
        count += maxR - minR;
        
        // 注意若為left和R同體的情況
        // 那就代表根本沒加上A[left]
        // 那我們更不能減掉
        if(minR > left)
            minSum -= A[left];
        if(maxR > left)
            maxSum -= A[left];
            
        left++;
    }
    
    return count;
}
