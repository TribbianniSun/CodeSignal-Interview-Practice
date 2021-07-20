bool containsCloseNums(vector<int> nums, int k) {
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++){
        int cur = nums[i];
        if(mp.count(cur) and i - mp[cur] <= k) return true;
        mp[cur] = i;
    }
    return false;
}
