struct Event{
    double x, y;
    bool operator< (const Event& w){
        if(w.x != x) return x < w.x;
        return y > w.y;
    }
};

vector<vector<double>> getSkyline(vector<vector<double>> buildings) {
    vector<Event> events;
    for(int i = 0; i < buildings.size(); i++){
        events.push_back({buildings[i][0], buildings[i][2]});
        events.push_back({buildings[i][0] + buildings[i][1], -buildings[i][2]});
    }
    sort(events.begin(), events.end());
    
    multiset<double> mySet;
    vector<vector<double>> ret;
    
    for(int i = 0; i < events.size(); i++){
        Event& focus = events[i];
        double x = focus.x, y = focus.y;
        if(y > 0){
            // add event
            mySet.insert(y);
            double cur_H = *mySet.rbegin();
            if(ret.size() == 0 or ret.back()[1] < cur_H){
                ret.push_back({x, cur_H});
            }
        }   
        else{
            // remove event
            double cur_H = mySet.size() ? *mySet.rbegin() : 0;
            mySet.erase(mySet.lower_bound(-y));
            double new_H = mySet.size() ? *mySet.rbegin() : 0;
            if(new_H < cur_H){
                ret.push_back({x, new_H});
            }
        } 
    }
    
    return ret;
}
