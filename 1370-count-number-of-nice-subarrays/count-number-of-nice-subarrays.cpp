class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mapp;
        mapp[0]=1;
        int ans=0;
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=(nums[i]%2==1);
            if(mapp.find(sum-k)!=mapp.end()){
                ans+=mapp[sum-k];
            }
            mapp[sum]++;
        }
        return ans;
    }
};