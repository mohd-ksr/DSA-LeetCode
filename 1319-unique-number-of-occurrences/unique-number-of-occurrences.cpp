class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mapp1,mapp2;
        for(int &a:arr)mapp1[a]++;
        for(auto &it:mapp1)mapp2[it.second]++;
        for(auto &it:mapp2)if(it.second!=1)return false;
        return true;
    }
};