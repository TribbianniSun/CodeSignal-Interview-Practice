int f[105][105];

int maximalSquare(vector<vector<char>> matrix) {
    memset(f, 0, sizeof f);
    int ret = 0;
    int n = matrix.size();
    if(n == 0) return 0;
    int m = matrix[0].size();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(matrix[i-1][j-1] == '0'){
                f[i][j] = 0;
                continue;
            }
            f[i][j] = min(f[i][j-1], f[i-1][j]);
            f[i][j] = min(f[i][j], f[i-1][j-1]) + 1;
            ret = max(ret, f[i][j]);
        }
    }
    return ret * ret;
}
