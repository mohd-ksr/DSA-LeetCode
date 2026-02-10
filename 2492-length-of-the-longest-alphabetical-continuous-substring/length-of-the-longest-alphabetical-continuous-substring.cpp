class Solution {
public:
    int longestContinuousSubstring(string s) {
        int count=1;
        int ans = 1;
        int n = s.length();
        char prev = s[0];
        for(int i=1; i<n; i++){
            if(s[i]==prev+1){
                count++;
            }
            else{
                count=1;
            }
            prev=s[i];
            ans = max(ans, count);
        }
        return ans;
    }
};