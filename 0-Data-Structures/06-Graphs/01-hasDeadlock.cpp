// topological sorting
bool hasDeadlock(vector<vector<int>> connections) {
    int n = connections.size();
    int indegree[n + 5];

    memset(indegree,0,sizeof indegree);
    
    for(auto& p : connections){
        for(int b : p)
            indegree[b] += 1;
        
    }
    
    
    queue<int> q;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0) q.push(i);
    }
    
    while(q.size()){
        int c = q.front(); q.pop();
        cnt += 1;
        if(connections[c].size() == 0) continue;
        for(int i : connections[c]){
            indegree[i] -= 1;
            if(!indegree[i]) q.push(i);
        }
    }
    
    return cnt != n;
    
}
