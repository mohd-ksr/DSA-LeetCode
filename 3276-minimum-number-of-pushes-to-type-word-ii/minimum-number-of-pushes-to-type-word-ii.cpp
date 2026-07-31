class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(auto ch:word){
            freq[ch-'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        for(auto ch:freq){
            cout<<ch<<" ";
        }
        int ans = 0;
        for(int i=0; i<26; i++){
            if(freq[i]==0)break;
            int m = (i/8)+1;
            ans+=m*freq[i];
        }
        return ans;
    }
};