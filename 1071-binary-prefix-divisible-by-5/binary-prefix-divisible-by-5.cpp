class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool>ans(n,false);
        int temp = 0;
        for(int i=0; i<n; i++){
            temp = ((temp<<1)+nums[i])%5;
            ans[i]=(temp%5==0);
        }
        return ans;
    }
};
// Time complexity O(n)