
bool sumOfTwo(vector<int> a, vector<int> b, int v) {
    unordered_set<int> s;
    for(int num : a){
        s.insert(v - num);
    }
    for(int num : b){
        if(s.count(num)) return true;
    }
    return false;
}
