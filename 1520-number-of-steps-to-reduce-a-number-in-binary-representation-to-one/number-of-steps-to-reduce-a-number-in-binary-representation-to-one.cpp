class Solution {
public:
    int numSteps(string s) {
        bool tog =false;
        int n = s.size();
        int ans = 0;
        for(int i=n-1; i>0; i--){
            if(s[i]=='0'){
                if(tog)ans+=2;
                else ans++;
            }
            else{
                if(tog)ans++;
                else{
                    ans+=2;
                    tog=true;
                }
            }
        }
        if(tog)ans++;
        return ans;
    }
};