bool containsDuplicates(vector<int> a) {
    unordered_set<int> s;
    for(int num : a){
        int t = s.size();
        s.insert(num);
        if(s.size() == t) return true;
    }
    return false;
}
