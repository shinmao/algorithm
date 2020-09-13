// https://leetcode.com/problems/heaters/discuss/95887/C%2B%2B-clean-solution-with-explanation
// 這裡的圖解已經很詳細，所以不再加以贅述
// 這裡其實不需要binary search
// 我們只要兩個都排好序
// 在未超過 heater 的位置前
// 最近的 heater 都會是他
int findRadius(vector<int>& houses, vector<int>& heaters) {
    if(houses.size() == 0 || heaters.size() == 0) return 0;
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    vector<int> res(houses.size(), INT_MAX);
    // find RH for each house
    for(int hs = 0, ht = 0; hs < houses.size() && ht < heaters.size(); ) {
        if(houses[hs] <= heaters[ht]){
            res[hs] = min(res[hs], heaters[ht] - houses[hs]);
            hs++;
        }else
            ht++;
    }
    // find LH for each house
    for(int hs = houses.size() - 1, ht = heaters.size() - 1; hs >= 0 && ht >= 0; ) {
        if(houses[hs] >= heaters[ht]) {
            res[hs] = min(res[hs], houses[hs] - heaters[ht]);
            hs--;
        }else
            ht--;
    }
    return *max_element(res.begin(), res.end());
}