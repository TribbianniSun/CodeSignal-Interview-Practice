bool sudoku2(vector<vector<char>> grid) {
    int col[10], row[10], box[10];
    memset(col, 0, sizeof col), memset(row, 0, sizeof row), memset(box, 0, sizeof box);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            char c = grid[i][j];
            if(c == '.') continue;
            int t = c - '0';
            if(col[i] & 1 << t) return false;
            if(row[j] & 1 << t) return false;
            if(box[i / 3 * 3 + j / 3] & 1 << t) return false;
            col[i] += 1 << t;
            row[j] += 1 << t;
            box[i / 3 * 3 + j / 3] += 1 << t;
        }
    }
    return true;
}
