vector<vector<string>> groupingDishes(vector<vector<string>> dishes) {
    vector<vector<string>> ret;
    map<string, vector<string> > mp;
    for(vector<string>& dish : dishes){
        for(int i = 1; i < dish.size(); i++){
            mp[dish[i]].push_back(dish[0]);
        }
    }
    for(auto&& [ingred, dish] : mp){
        sort(dish.begin(), dish.end());
    }
    for(auto&& [ingred, dish] : mp){
        if(dish.size() < 2) continue;
        vector<string> c = dish;
        c.insert(c.begin(), ingred);
        ret.push_back(c);
    }
    return ret;
}
