char firstNotRepeatingCharacter(string s) {
    int f[30];
    memset(f, 0, sizeof f);
    for(char c : s) f[c - 'a'] += 1;
    for(char c : s) if(f[c - 'a'] == 1) return c; 
    return '_';
}
