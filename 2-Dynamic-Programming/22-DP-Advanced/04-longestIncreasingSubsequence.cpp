int longestIncreasingSubsequence(vector<int> sequence) {
    set<int> s;
    for(int num : sequence){
        auto it = s.lower_bound(num);
        if(it != s.end()) s.erase(it);
        s.insert(num);
    }
    return s.size();
}
