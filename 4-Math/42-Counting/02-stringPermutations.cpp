void dfs(vector<string>& global_ret, vector<char>& local_ret, vector<char>& elements, vector<bool>& seen){

    if(local_ret.size() == elements.size()){
        global_ret.push_back(string(local_ret.begin(), local_ret.end()));
        return;
    }
    
    for(int i = 0; i < elements.size(); i++){
        if(seen[i]) continue;
        if(i != 0 and elements[i] == elements[i - 1] and !seen[i - 1]) continue;
        local_ret.push_back(elements[i]);
        seen[i] = true;
        dfs(global_ret, local_ret, elements, seen);
        local_ret.pop_back();
        seen[i] = false;
    }
}

vector<string> stringPermutations(string s) {
    vector<string> global_ret;
    vector<char> local_ret;
    vector<bool> seen(s.size(), false);
    vector<char> elements;
    for(char c : s) elements.push_back(c);
    sort(elements.begin(), elements.end());
    dfs(global_ret, local_ret, elements, seen);
    return global_ret;
}
