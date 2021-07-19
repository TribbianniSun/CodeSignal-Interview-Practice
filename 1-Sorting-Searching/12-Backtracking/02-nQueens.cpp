vector<vector<int>> global_ret;
vector<int> local_ret;

int col, row, dg, udg;

inline void dfs(int i, int j, int u, int n){
        
    if(j == n){
        dfs(i + 1, 0, u, n);
        return;
    }
    
    if(i == n and u == n){
        global_ret.push_back(local_ret);
        return;
    }
    
    if(i == n){
        return;
    }
    
    
    if(!(col & 1 << i) and !(row & 1 << j) and !(dg & (1 << (i + j))) and !(udg & 1 << (i - j + n)) ){
        col += 1 << i, row += 1 << j, dg += 1 << (i + j), udg += 1 << (i - j + n);
        local_ret.push_back(j + 1);
        dfs(i, j + 1, u + 1, n);
        local_ret.pop_back();
        col -= 1 << i, row -= 1 << j, dg -= 1 << (i + j), udg -= 1 << (i - j + n);
    }
    dfs(i, j + 1, u, n);
}

vector<vector<int>> nQueens(int n) {
    col = dg = udg = row = 0;
    dfs(0, 0, 0, n);
    sort(global_ret.begin(), global_ret.end());
    return global_ret;
}
