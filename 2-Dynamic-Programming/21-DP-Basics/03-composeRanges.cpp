vector<string> composeRanges(vector<int> nums) {
    vector<string> ret;
    if(nums.size() == 0) return ret;
    int i = 0;
    int cur = nums[0];
    int n = nums.size();
    
    for(int j = 0; j < n;){
        
        int start = cur;
        j += 1;
        while(j < n and nums[j] == cur + 1){
            cur = nums[j];
            j += 1;
        }    
        
        string focus;
        if(start != cur)
            focus = to_string(start) + "->" + to_string(cur);
        else {
            focus = to_string(start);
        }
        
        if(j < n)
            cur = nums[j];
            
        ret.push_back(focus);
    }
    return ret;
}
