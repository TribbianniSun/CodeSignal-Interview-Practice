int getNumber(vector<vector<int>>& left_right_enemy, vector<vector<int>>& up_down_enemy, vector<vector<int>>& left_right_wall, vector<vector<int>>& right_left_wall,
vector<vector<int>>& up_down_wall, vector<vector<int>>& down_up_wall, int i, int j){
    
    int left_wall = left_right_wall[i][j] == 0 ? 1 : left_right_wall[i][j];
    int right_wall = right_left_wall[i][j] == 0 ? 1 : right_left_wall[i][j];
    
    int up_wall = up_down_wall[i][j] == 0 ? 1 : up_down_wall[i][j];
    int down_wall = down_up_wall[i][j] == 0 ? 1 : down_up_wall[i][j];
    

    
    return  up_down_enemy[down_wall][j] - up_down_enemy[up_wall - 1][j] + left_right_enemy[i][right_wall] - left_right_enemy[i][left_wall - 1];
}

int bomber(vector<vector<char>> field) {
    if(field.size() == 0) return 0;
    int n = field.size(),  m = field[0].size();
    
    vector<vector<int>> left_right_enemy(n + 5, vector<int>(m + 5, 0));
    vector<vector<int>> up_down_enemy(n + 5, vector<int>(m + 5, 0));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int val = field[i-1][j-1] == 'E';
            left_right_enemy[i][j] = left_right_enemy[i][j - 1] + val;
            up_down_enemy[i][j] = up_down_enemy[i - 1][j] + val;
        }
    }
    
    
    vector<vector<int>> left_right_wall(n + 5, vector<int>(m + 5, 0));
    vector<vector<int>> right_left_wall(n + 5, vector<int>(m + 5, m));
    vector<vector<int>> up_down_wall(n + 5, vector<int>(m + 5, 0)); 
    vector<vector<int>> down_up_wall(n + 5, vector<int>(m + 5, n));
    
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            bool isWall = field[i - 1][j - 1] == 'W';
            if(isWall){
                left_right_wall[i][j] = j;
                up_down_wall[i][j] = i;
            }
            else{
                left_right_wall[i][j] = left_right_wall[i][j - 1];
                up_down_wall[i][j] = up_down_wall[i - 1][j];
            }
        }
    }
    
    
    
    for(int i = n; i >= 1; i--){
        for(int j = m; j >= 1; j--){
            bool isWall = field[i - 1][j - 1] == 'W';
            if(isWall){
                right_left_wall[i][j] = j;
                down_up_wall[i][j] = i;
            }
            else{
                right_left_wall[i][j] = right_left_wall[i][j + 1];
                down_up_wall[i][j] = down_up_wall[i + 1][j];
            }
            
            if(i == 3 and j == 2) cout << down_up_wall[i][j] << endl;
            
        }
    }
    
    int ret = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(field[i - 1][j - 1] == '0') ret = max(ret, getNumber(left_right_enemy, up_down_enemy, left_right_wall, right_left_wall, up_down_wall, down_up_wall, i, j));
        }
    }
    
    return ret;
}
