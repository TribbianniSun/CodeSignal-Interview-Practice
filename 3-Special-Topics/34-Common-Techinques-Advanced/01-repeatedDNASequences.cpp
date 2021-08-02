vector<string> repeatedDNASequences(string s) {
    vector<string> ret;
    if(s.size() <= 10) return ret;
    unordered_map<string, int> mp;
    for(int i = 0; i <= s.size() - 10; i++){
        mp[s.substr(i, 10)] += 1;
    }
    for(auto&& [s, freq] : mp){
        if(freq >= 2) ret.push_back(s);
    }
    sort(ret.begin(), ret.end());
    return ret;
}
