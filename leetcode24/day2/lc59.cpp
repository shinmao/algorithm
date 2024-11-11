class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        // the start loc of each round
        int x = 0, y = 0;
        // how many rounds should I visit
        int round = n / 2;
        // (x, y) for the center
        int mid = n / 2;
        // the value we want to assign to cell
        int num = 1;
        int bound = 1;
        // curr loc
        int i = 0, j = 0;

        // 每次填值都是左閉右開
        while (round --) {
            i = x;
            j = y;

            // from left to right; i is fixed
            for (j; j < n - bound; j++) {
                res[i][j] = num++;
            }

            // from up to down; j is fixed
            for (i; i < n - bound; i++) {
                res[i][j] = num++;
            }

            // from right to left; i is fixed
            for (j; j > y; j--) {
                res[i][j] = num++;
            }

            // from down to up; j is fixed
            for (i; i > x; i--) {
                res[i][j] = num++;
            }

            // new start loc of a round
            x++;
            y++;

            // boundary +1
            bound++;
        }

        if (n % 2) {
            res[mid][mid] = num;
        }

        return res;
    }
};