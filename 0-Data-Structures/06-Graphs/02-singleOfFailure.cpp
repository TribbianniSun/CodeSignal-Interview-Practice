// tarjan

const int N = 305;

int dfn[N], low[N], timestamp;
int id[N], dcc_cnt;
vector<vector<int>> bridge;
vector<int> graph[N];
stack<int> myStack;

void tarjan(int u, int from){
    
    dfn[u] = low[u] = timestamp ++;
    myStack.push(u);
    
    
    for(int j : graph[u]){
        if(!dfn[j]){
            tarjan(j, u);
            low[u] = min(low[u], low[j]);
            if(dfn[u] < low[j]){
                bridge.push_back({u, j});
            }
        }
        else if(j != from){
            low[u] = min(low[u], dfn[j]);
        }
    }   
    
    
    if(dfn[u] == low[u]){
        int y;
        dcc_cnt += 1;
        do{
            y = myStack.top(); myStack.pop();
            id[y] = dcc_cnt;
        }while(y != u);
    }
}

int singlePointOfFailure(vector<vector<int>> connections) {
    for(int i = 0; i < connections.size(); i++){
        for(int j = 0; j < connections[i].size(); j++){
            if(connections[i][j]) graph[i].push_back(j);
        }
    }
    cout << dcc_cnt;
    tarjan(0, -1);
    return bridge.size();
}
