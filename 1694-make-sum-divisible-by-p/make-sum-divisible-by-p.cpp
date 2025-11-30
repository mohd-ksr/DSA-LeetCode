class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int sum = 0;
        for(int num:nums)sum=(num+sum)%p;
        int t = sum%p;
        if(t==0)return 0;
        unordered_map<int, int>mapp;
        mapp[0]=-1;
        int newSum = 0;
        int ans=n;
        for(int i=0; i<n; i++){
            newSum = (newSum+nums[i])%p;
            int need = (newSum-t+p)%p;
            if(mapp.count(need)){
                ans = min(ans,i-mapp[need]);
            }
            mapp[newSum]=i;
        }
        return ans==n?-1:ans;
    }
};
// Time complexity O(n)
// Space complexity O(n)