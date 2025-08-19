class Solution {
private:
    bool isAnagram(string str1, string str2){
        unordered_map<char,char>mapp;
        for(auto &ch:str1)mapp[ch]++;
        for(auto &ch:str2)mapp[ch]--;
        for(auto &it:mapp)if(it.second!=0)return false;
        return true;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        for(auto &str:words){
            if(ans.empty())ans.push_back(str);
            else if(!isAnagram(ans.back(),str))ans.push_back(str);
        }
        return ans;
    }
};