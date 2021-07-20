int houseRobber(vector<int> nums) {
    int take = 0, not_take = 0;
    for(int num : nums){
        int cur_take = max(take, not_take + num);
        int cur_not_take = max(take, not_take);
        take = cur_take, not_take = cur_not_take;
    }
    return max(take, not_take);
}
