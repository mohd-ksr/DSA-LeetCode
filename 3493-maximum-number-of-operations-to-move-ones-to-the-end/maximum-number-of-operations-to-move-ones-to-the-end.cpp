class Solution {
public:
    int maxOperations(string s) {
        int c1 = 0;
        int n = s.size();
        int i = 0;
        int ans = 0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]=='1'){
                n--;
            }
            else break;
        }
        while(i<n){
            if(s[i]=='1'){
                while(s[i]=='1' && i<n){
                    c1++;
                    i++;
                }
                ans+=c1;
            }
            i++;
        }
        return ans;
    }
};