vector<int> mostVisited(int n, vector<int>& rounds) {
    vector<int> res;
    int start = *(rounds.begin()), end = *(--rounds.end());
    if(start <= end)
        for(int i = start; i <= end; ++i) res.push_back(i);
    else {
        for(int i = 1; i <= end; ++i) res.push_back(i);
        for(int i = start; i <= n; ++i) res.push_back(i);
    }

    return res;
}