class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mapp;
        for(int i=0; i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            mapp[s].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto &it:mapp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
// Time Complexity O(n)
// Space Complexity O(n)