class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int>mapp;
        int i=0, j=0, maxFreq=0, ans=0;
        while(j<n){
            mapp[s[j]]++;
            maxFreq = max(maxFreq, mapp[s[j]]);
            while((j-i+1)-maxFreq > k){
                mapp[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};