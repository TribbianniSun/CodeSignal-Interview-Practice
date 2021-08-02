void dfs(vector<string>& global_ret, vector<char>& local_ret, vector<char> mp[10], string buttons, int idx){
    if(idx == buttons.size()) {
        global_ret.push_back(string(local_ret.begin(), local_ret.end()));
        return;
    }
    for(char c : mp[buttons[idx] - '2']){
        local_ret.push_back(c);
        dfs(global_ret, local_ret, mp, buttons, idx + 1);
        local_ret.pop_back();
    }
    return;
}
vector<string> pressingButtons(string buttons) {
    vector<string> global_ret;
    if(buttons.size() == 0) return global_ret;
    vector<char> local_ret;
    vector<char> mp[10] = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g','h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}, {}, {}};
    dfs(global_ret, local_ret, mp, buttons, 0);
    return global_ret;
    
}
