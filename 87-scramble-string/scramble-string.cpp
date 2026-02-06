class Solution {
public:
    unordered_map<string, bool>dp;
    bool isScramble(string s1, string s2) {
        if(s1.compare(s2)==0)return dp[s1+" "+s2]=true;
        if(s1.length()<=1)return dp[s1+" "+s2]=false;
        if(dp.find(s1+" "+s2)!=dp.end())return dp[s1+" "+s2];
        int n = s1.length();
        bool ans = false;
        for(int i=1; i<n; i++){
            if((isScramble(s1.substr(0,i), s2.substr(n-i, i)) && isScramble(s1.substr(i, n-i), s2.substr(0, n-i))) || (isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i, n-i), s2.substr(i, n-i)))){
                ans=true;
                break;
            }
        }

        return dp[s1+" "+s2]=ans;
    }
};