class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>freq(26,0);
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int len = 0;
            for(int j=i; j<n; j++){
                int ind = s[j]-'a';
                freq[ind]++;
                if(freq[ind]>2)break;
                len++;
            }
            ans = max(len, ans);
            for(int k=0; k<26; k++){
                freq[k]=0;
            }
        }
        return ans;
    }
};