int firstDuplicate(vector<int> a) {
    for(int num : a){
        int idx = abs(num) - 1;
        if(a[idx] < 0){
            return abs(num);
        }
        else{
            a[idx] = -a[idx];
        }
    }
    return -1;
}
