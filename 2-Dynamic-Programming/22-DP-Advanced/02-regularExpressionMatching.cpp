bool regularExpressionMatching(string s, string p) {
    bool dp[50][50];
    memset(dp, 0, sizeof dp);
    dp[0][0] = true;
    
    for(int j = 1; j <= p.size(); j++){
        char cp = p[j - 1];
        if(cp == '*') dp[0][j] = dp[0][j-2];
    }
    
    for(int i = 1; i <= s.size(); i++){
        for(int j = 1; j <= p.size(); j++){
            char cs = s[i - 1], cp = p[j - 1];
            if(cs == cp or cp == '.'){
                dp[i][j] = dp[i-1][j-1];
            }
            if(cp == '*'){
                // pick 0
                // pick 1
                dp[i][j] = dp[i][j - 2];
                dp[i][j] = dp[i][j] or dp[i][j-1];
                
                if(p[j-2] == '.' or p[j-2] == s[i-2]){
                    dp[i][j] = dp[i][j] or dp[i-1][j];
                }
            }
        }
    }
    
    
    return dp[s.size()][p.size()];
}