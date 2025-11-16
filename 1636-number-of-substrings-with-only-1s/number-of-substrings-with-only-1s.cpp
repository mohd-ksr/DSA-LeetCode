class Solution {
public:
    int numSub(string s) {
        int n=s.size();
        int ans = 0;
        int MOD = 1e9 + 7;
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                long long temp = 0;
                while(i<n && s[i]=='1'){
                    temp++;
                    i++;
                }
                ans = (ans + ((temp+1)*temp)/2)%MOD;
            }
        }
        return ans;
    }
};
// time complexity O(n)