int sumInRange(vector<int> nums, vector<vector<int>> queries) {
    int mod = 1e9 + 7;
    for(int i = 1; i < nums.size(); i++){
        nums[i] = (nums[i] + nums[i - 1]) % mod;
    }
    long long ret = 0;
    for(vector<int>& q : queries){
        int a = q[0], b = q[1];
        int left = a == 0 ? 0 : nums[a - 1];
        int right = nums[b];
        ret = (ret + right - left + mod) % mod;
    }
    return ret;
}
