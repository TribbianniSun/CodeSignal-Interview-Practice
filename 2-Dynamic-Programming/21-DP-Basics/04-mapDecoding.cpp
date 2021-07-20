int mapDecoding(string message) {
    int mod = 1e9 + 7;
    int pre1 = 1, pre2 = 2;
    for(int i = 0; i < message.size(); i++){
        int focus = 0;
        if(message[i] != '0') focus = (focus + pre1) % mod;
        if(i != 0 and stoi(message.substr(i - 1, 2)) >= 10 and stoi(message.substr(i - 1, 2)) <= 26){
            focus = (focus + pre2) % mod;
        }
        pre2 = pre1;
        pre1 = focus;
    }
    return pre1;
}