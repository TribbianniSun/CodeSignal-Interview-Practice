int decode(string& s, int mp[]){
    int ret = 0;
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        int t = mp[c];
        if(t == 0 and i == 0 and s.size() > 1) return -1;
        ret = ret * 10 + t;
    }
    return ret;
}

bool isCryptSolution(vector<string> crypt, vector<vector<char>> solution) {
    int mp[300];
    for(auto & s : solution) mp[s[0]] = s[1] - '0';
    int a = decode(crypt[0], mp);
    int b = decode(crypt[1], mp);
    int c = decode(crypt[2], mp);
    if(a == -1 or b == -1 or c == -1) return false;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    return a + b == c;
}
