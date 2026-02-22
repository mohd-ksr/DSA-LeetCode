class Solution {
public:
    int binaryGap(int n) {
        string s = "";
        while(n){
            s.push_back('0'+(n&1));
            n>>=1;
        }
        int prev = -1;
        n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                if(prev!=-1){
                    ans = max(ans, i-prev);
                }
                prev=i;
            }
        }
        return ans;
    }
};