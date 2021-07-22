vector<int> findLongestSubarrayBySum(int s, vector<int> arr) {
    unordered_map<int, int> mp;
    int focusingSum = 0;
    int ret = -1;
    int startIdx = 0;
    mp[0] = -1;
    for(int i = 0; i < arr.size(); i++){
        int num = arr[i];   
        focusingSum += num;
        int target = focusingSum - s;
        
        if(mp.count(target) and i - mp[target] + 1 > ret){
            ret = max(ret, i - mp[target] + 1);
            startIdx = mp[target];
        }
            
        if(mp.count(focusingSum)) mp[focusingSum] = min(mp[focusingSum], i);
        else mp[focusingSum] = i;
    }
    if(ret == -1) return {ret};
    return {startIdx + 2, ret + startIdx};
}
