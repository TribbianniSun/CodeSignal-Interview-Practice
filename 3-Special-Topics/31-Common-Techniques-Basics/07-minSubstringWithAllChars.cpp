bool check(int q[]){
    for(int i = 0; i < 30; i++){
        if(q[i] > 0) return false;
    }
    return true;
}

string minSubstringWithAllChars(string s, string t) {
    if(t == "") return "";
    int freq[30];
    memset(freq, 0, sizeof freq);
    for(char c : t){
        freq[c - 'a'] += 1;
    }

    int n = s.size();
    int len = 2e9, startIdx = -1;
    
    for (int i = 0, j = 0; i < n; ++i) {
        
        freq[s[i] - 'a'] -= 1;
        
        // inside the while loop, the substring is valid
        while(j <= i and check(freq)){
            if(len > i - j + 1){
                startIdx = j;
                len = i - j + 1;
            }
            freq[s[j] - 'a'] += 1;
            j += 1;
        }   
    }
    
    return s.substr(startIdx, len);
    

}
