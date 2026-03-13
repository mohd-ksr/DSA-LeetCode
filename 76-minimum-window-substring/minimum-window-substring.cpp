class Solution {
private:
    bool isPresent(unordered_map<char, int>&mapp, unordered_map<char, int>&mapp2){
        for(auto &it:mapp){
            if(mapp2.find(it.first)==mapp2.end() || it.second > mapp2[it.first])return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int>mapp;
        for(auto ch:t)mapp[ch]++;
        int l=0, r=0;
        int start=0, minLen=INT_MAX;
        unordered_map<char, int>mapp2;
        while(r<n){
            mapp2[s[r]]++;
            r++; 
            while(isPresent(mapp, mapp2)){
                if(minLen > r-l){
                    minLen = r-l;
                    start = l;
                }
                mapp2[s[l]]--;
                l++;
            }    
        }
        return (minLen==INT_MAX? "" : s.substr(start, minLen));
    }
};