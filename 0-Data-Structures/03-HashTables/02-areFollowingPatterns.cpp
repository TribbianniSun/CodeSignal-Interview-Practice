bool areFollowingPatterns(vector<string> strings, vector<string> patterns) {
    unordered_map<string, string> s_p;
    unordered_map<string, string> p_s;
    for(int i = 0; i < patterns.size(); i++){
        string s = strings[i], p = patterns[i];
        if(s_p.count(s) and s_p[s] != p) return false;
        if(p_s.count(p) and p_s[p] != s) return false;
        s_p[s] = p;
        p_s[p] = s; 
    }
    return true;
}
