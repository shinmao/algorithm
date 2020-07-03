// idea: continue simulation and we can find the rule
// beats over 63% of submission
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        for(N = (N-1) % 14 + 1; N > 0; --N){
            vector<int> res(8, 0);
            for(int i = 1; i < 7; ++i){
                res.at(i) = cells.at(i-1) == cells.at(i+1) ? 1 : 0;
            }
            cells = res;
        }
        return cells;
    }
};