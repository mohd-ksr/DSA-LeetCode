class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int k=0; k<n; k++){
            ans++;
            int i=k-1;
            int j=k+1;
            while(i>=0 && j<n){
                if(s[i]!=s[j])break;
                ans++;
                i--;
                j++;
            }
            i=k-1;
            j=k;
            while(i>=0 && j<n){
                if(s[i]!=s[j])break;
                ans++;
                i--;
                j++;
            }
        }
        return ans;
    }
};