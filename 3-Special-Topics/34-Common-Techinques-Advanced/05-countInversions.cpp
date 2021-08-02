int tr[2020];
int base = 1010;


int lowbit(int x){
    return x & -x;
}


void update(int u, int c){
    for(int i = u; i < 2020; i += lowbit(i)){
        tr[i] += c;
    }
}

int query(int u){
    int ret = 0;
    for(int i = u; i > 0; i -= lowbit(i)){
        ret += tr[i];
    }
    return ret;
}


int countInversions(vector<int> a) {
    int ret = 0;
    int mod = 1e9 + 7;
    
    for(int i = a.size() - 1; i >= 0; i--){
        update(a[i] + base, 1);
        ret = (ret + query(a[i] + base - 1)) % mod;
    }
    
    return ret;
}
