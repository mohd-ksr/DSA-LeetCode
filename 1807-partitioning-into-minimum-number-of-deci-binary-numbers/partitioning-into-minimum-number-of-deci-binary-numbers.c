int minPartitions(char* n) {
    int ans = 0;
    for(int i=0; n[i] != '\0'; i++){
        int temp = n[i] - '0';
        ans = (ans>temp? ans:temp);
        if(ans==9)return ans;
    }
    return ans;
}