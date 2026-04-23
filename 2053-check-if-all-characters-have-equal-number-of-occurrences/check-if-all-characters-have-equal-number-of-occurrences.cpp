class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int>freq(26,0);
        for(auto &ch:s){
            freq[ch-'a']++;
        }

        int count=-1;
        for(int i=0; i<26; i++){
            if(freq[i]==0)continue;
            if(count!=-1 && count!=freq[i])return false;
            count=freq[i];
        }
        return true;
    }
};