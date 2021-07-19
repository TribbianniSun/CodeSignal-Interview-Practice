void dfs(vector<int>& path, vector<vector<int>>& global_ret, int u, int n, int k){
    if(u > n) return;
    if(u == n){
        vector<int> ret = path;
        global_ret.push_back(ret);
        return;
    }
    for(int i = 1; i <= k; i++){
        path.push_back(i);
        dfs(path, global_ret, u + i, n, k);
        path.pop_back();
    }
}
vector<vector<int>> climbingStaircase(int n, int k) {
    vector<int> path;
    vector<vector<int>> global_ret;
    dfs(path, global_ret, 0, n, k);
    return global_ret;
}
