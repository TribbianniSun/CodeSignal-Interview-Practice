int possibleSums(vector<int> coins, vector<int> quantity) {
    unordered_set<int> s;
    s.insert(0);

    for(int i = 0 ; i < coins.size(); i++){
        unordered_set<int> back;
        back = s;        
        for(int j = 1; j <= quantity[i]; j++){
            for(int t : s){
                back.insert(t + j * coins[i]);
            }
        }
        s = back;
    }
    return s.size() - 1;
    
}
