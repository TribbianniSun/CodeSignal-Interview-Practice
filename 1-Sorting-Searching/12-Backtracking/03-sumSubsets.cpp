vector<vector<int>> global_ret;
vector<int> path;
bool seen[100];

inline void dfs(int i, int u, int target, vector<int>& arr){

    if(u > target) return;
    
    if(u == target){
        vector<int> ret = path;
        sort(ret.begin(), ret.end());
        global_ret.push_back(ret);
        return;
    }
    
    if(i == arr.size()) return;
    
    dfs(i + 1, u, target, arr);
    
    // only prune the case where I would like to pick it
    // if we are not picking that, we cannot terminate that early
    // like case 5,4,2,2,1 -> target is 5
    // we do not want to terminate the second 2 if we are not picking that number
    if(i != 0 and arr[i] == arr[i-1] and !seen[i - 1]) return;
    path.push_back(arr[i]);
    seen[i] = true;
    dfs(i + 1, u + arr[i], target, arr);
    seen[i] = false;
    path.pop_back();
}

vector<vector<int>> sumSubsets(vector<int> arr, int num) {
    memset(seen, 0, sizeof seen);
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    dfs(0, 0, num, arr);
    sort(global_ret.begin(), global_ret.end());
    return global_ret;   
}
