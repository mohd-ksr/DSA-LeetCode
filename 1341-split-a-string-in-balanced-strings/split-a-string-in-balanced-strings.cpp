class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0;
        int l=0;
        for(auto ch:s){
            if(ch=='L')l++;
            else l--;
            if(l==0)ans++;
        }
        return ans;
    }
};