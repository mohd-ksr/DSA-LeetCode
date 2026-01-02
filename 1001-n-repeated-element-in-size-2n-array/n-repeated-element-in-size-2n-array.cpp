class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n2 = nums.size();
        int n = n2/2;
        unordered_map<int, int>mapp;
        for(auto &num:nums)mapp[num]++;
        for(auto &it:mapp)if(it.second==n)return it.first;
        return -1;
    }
};
// Time Complexity O(n)