class Solution {
private:
    unordered_map<char, int>m1;
    unordered_map<char, int>m2;
    bool isOK(){
        for(auto it:m1){
            if(m2.find(it.first)==m2.end() || m2[it.first] < it.second)return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        for(auto ch:t){
            m1[ch]++;
        }
        int i=0,j=0;
        int minLen = INT_MAX;
        int start = 0;
        int m = s.size();
        while(j<m){
            m2[s[j]]++;
            while(isOK()){
                if(minLen > j-i+1){
                    minLen = j-i+1;
                    start = i;
                }
                m2[s[i]]--;
                i++;
            }
            j++;
        }
        if(minLen==INT_MAX)return "";
        return s.substr(start, minLen);
    }
};