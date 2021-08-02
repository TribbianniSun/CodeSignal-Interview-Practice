int insertBits(int n, int a, int b, int k) {
    for(int i = a; i <= b; i++){
        if(n & 1 << i) n -= 1 << i;
    }
    for(int i = a; i <= b; i++){
        if(k & (1 << (i - a))) n += (1 << (i));
    }
    return n;
}
