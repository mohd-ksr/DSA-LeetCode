class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        n-=2;
        unordered_map<int,int>mapp;
        for(int n:nums){
            mapp[n]++;
        }
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(mapp[i]>1)ans.push_back(i);
        }
        return ans;
    }
};