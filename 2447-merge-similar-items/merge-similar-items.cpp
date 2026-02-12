class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int>mapp;
        for(auto it:items1){
            mapp[it[0]]+=it[1];
        }
        for(auto it:items2){
            mapp[it[0]]+=it[1];
        }
        vector<vector<int>>ans;
        for(auto &it:mapp){
            ans.push_back({it.first, it.second});
        }
        return ans;
    }
};