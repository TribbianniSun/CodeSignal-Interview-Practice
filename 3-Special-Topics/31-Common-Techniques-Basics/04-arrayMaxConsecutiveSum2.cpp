int arrayMaxConsecutiveSum2(vector<int> inputArray) {
    int ret = -2e9;
    int cur_s = 0;
    for(int num : inputArray){
        if(cur_s < 0) cur_s = 0;
        cur_s += num;
        ret = max(ret, cur_s);
    }
    return ret;
}
