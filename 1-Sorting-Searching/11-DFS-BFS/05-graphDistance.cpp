typedef pair<int, int> PII;
const int N = 105;
vector<PII> graph[N];
int dist[N];
bool st[N];
int n;




inline void dijkstra(int s){
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, s});
    while(pq.size()){
        auto p = pq.top(); pq.pop();
        int c = p.first, ver = p.second;
        if(st[ver]) continue;
        st[ver] = true;
        for(auto& p : graph[ver]){
            int a = p.first, b = p.second;
            if(dist[a] > dist[ver] + b){
                dist[a] = dist[ver] + b;
                pq.push({dist[a], a});
            }
        }
    }
}


vector<int> graphDistances(vector<vector<int>> g, int s) {
    n = g.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(g[i][j] == -1) continue;
            graph[i].push_back({j, g[i][j]});
        }
    }
    dijkstra(s);
    vector<int> ret;
    for(int i = 0; i < n; i++){
        ret.push_back(dist[i]);
    }
    return ret;
}
