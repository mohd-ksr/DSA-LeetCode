class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>>mapp;
        int n =nums.size();
        for(int i=0; i<n; i++){
            mapp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for(auto &it:mapp){
            if(it.second.size()<3)continue;
            int i=0, j=1, k=2;
            while(k<it.second.size()){
                ans = min(ans, 2*(max({it.second[i], it.second[j], it.second[k]})-min({it.second[i], it.second[j], it.second[k]})));
                i++;
                j++;
                k++;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};