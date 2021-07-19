// Floyd Warshall Algorithm 

bool currencyArbitrage(vector<vector<double>> exchange) {
    int n = exchange.size();
    for (int k = 0; k < n; k ++ )
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
               exchange[i][j] = max(exchange[i][j], exchange[i][k] * exchange[k][j]);
    
    for(int i = 0; i < n; i++){
        if(exchange[i][i] > 1) return true;
    }
    
    return false;
}
