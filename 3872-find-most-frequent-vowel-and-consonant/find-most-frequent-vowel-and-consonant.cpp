class Solution {
private:
    bool isVowel(char &ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')return true;
        return false;
    }
public:
    int maxFreqSum(string s) {
        unordered_map<char, int>c,v;
        for(auto &ch:s){
            if(isVowel(ch))v[ch]++;
            else c[ch]++;
        }
        int maxV = 0, maxC = 0;
        for(auto &it:c){
            if(it.second > maxC) maxC = it.second;
        }
        for(auto &it:v){
            if(it.second > maxV) maxV = it.second;
        }
        return maxC+maxV;
    }
};
// Time Complexity O(n)
// Space Complexity O(n)