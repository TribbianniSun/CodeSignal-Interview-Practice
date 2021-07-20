int paintHouses(vector<vector<int>> cost) {
    int n = cost.size();
    int dp[n + 1][4];
    memset(dp, 0x3f, sizeof dp);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            if(i == 0) dp[i][j] = cost[i][j];
            else{
                int local_min = 2e9;
                for(int k = 0; k < 3; k++){
                    if(k == j) continue;
                    local_min = min(local_min, dp[i-1][k]);
                }
                dp[i][j] = local_min + cost[i][j];
            }
        }
    }
    return min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
}
