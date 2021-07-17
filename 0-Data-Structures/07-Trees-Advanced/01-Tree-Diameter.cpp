vector<int> graph[10050];
bool st[10050];

int startNode = -1;
int diameter = 0;

inline void bfs(int s){
    memset(st, 0, sizeof st);
    st[s] = true;
    queue<int> q;
    q.push(s);
    int step = 0;
    while(q.size()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            int c = q.front(); q.pop();
            for(int ni : graph[c]){
                if(!st[ni]){
                    q.push(ni);
                }
                st[ni] = true;
            }
            startNode = c;
        }
        step += 1;
    }
    
    diameter = max(diameter, step);
}


int treeDiameter(int n, vector<vector<int>> tree) {
    if(n == 1) return 0;
    for(auto edge : tree){
        int a = edge[0], b = edge[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    bfs(tree[0][0]);
    bfs(startNode);
    
    return diameter - 1;
    
}
