vector<vector<int>> rotateImage(vector<vector<int>> a) {
    reverse(a.begin(), a.end());
    int n = a.size();
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            swap(a[i][j], a[j][i]);
        }
    }
    return a;
}
