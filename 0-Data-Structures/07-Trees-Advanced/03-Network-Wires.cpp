int p[105];
struct Edge{
    int a, b, c;
}edges[105 * 50];


int numberOfEdges;

bool cmp(Edge& e1, Edge& e2){
    return e1.c < e2.c;
}


int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}



int networkWires(int n, vector<vector<int>> wires) {
    for(int i = 0; i <= n; i++) p[i] = i;
    for(vector<int>& edge : wires){
        int a = edge[0], b = edge[1], c = edge[2];
        edges[numberOfEdges++] = {a, b, c};
    }    
    
    sort(edges, edges + numberOfEdges, cmp);
    
    int ret = 0;
    for(int i = 0; i < numberOfEdges; i++){
        auto e = edges[i];
        int a = e.a, b = e.b, c = e.c;
        int pa = find(a), pb = find(b);
        if(pa != pb){
            ret += c;
            p[pa] = pb;
        }
    }
    
    
    return ret;

}
