class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int>freq(n+maxi, 0);
        for(auto &num:nums)freq[num]++;
        int ans = 0;
        for(int i=0; i<freq.size(); i++){
            if(freq[i]<=1)continue;

            int dup = freq[i]-1;
            freq[i+1]+=dup;
            ans+=dup;
        }
        return ans;
    }
};