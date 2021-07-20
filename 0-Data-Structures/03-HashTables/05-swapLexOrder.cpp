const int N = 1e4 + 10;
unordered_map<int,int> mp;
vector<char> group_char[N];
int idx;
vector<int> group_idx[N];

int p[N];

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}




string swapLexOrder(string str, vector<vector<int>> pairs) {
    int n = str.size();
    int m = pairs.size();
    for(int i = 0; i < n; i++) p[i] = i;
    for(int i = 0; i < m; i++){
        int a = pairs[i][0] - 1, b = pairs[i][1] - 1;
        int pa = find(a), pb = find(b);
        if(pa != pb) p[pa] = pb;
    }
    
    for(int i = 0; i < n; i++){
        int pi = find(i);
        if(!mp.count(pi)){
            mp[pi] = idx++;    
        }
        group_idx[mp[pi]].push_back(i);
        group_char[mp[pi]].push_back(str[i]);
    }
    
    for(int i = 0; i < idx; i++){
        sort(group_idx[i].begin(), group_idx[i].end());
        sort(group_char[i].begin(), group_char[i].end());
        reverse(group_char[i].begin(), group_char[i].end());
    }
    
    vector<char> ret(n, ',');
    for(int i = 0; i < idx; i++){
        for(int j = 0; j < group_char[i].size(); j++){
            ret[group_idx[i][j]] = group_char[i][j];
        }
    }
    
    return string(ret.begin(), ret.end());
    
}
