int getCount(int x){
    int ret = 0, i = 7;
    while(i > 0 and x & 1 << i){
        ret += 1;
        i -= 1;
    }
    return ret;
}

bool streamValidation(vector<int> stream) {
    for(int i = 0; i < stream.size(); ){
        int curNum = getCount(stream[i]);
        if(curNum > 4) return false;
        if(curNum == 1) return false;
        if(curNum > stream.size() - i) return false;
        for(int j = 1; j < curNum; j++){
            i += 1;
            int nextNum = getCount(stream[i]);
            if(nextNum != 1) return false;
        }
        i += 1;
    }    
    return true;
}
