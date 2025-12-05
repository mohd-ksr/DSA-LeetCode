class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for(auto &n:nums)sum+=n;
        int sum2 = 0, ans = -1;
        for(auto &n:nums){
            sum2+=n;
            int d = abs(sum2-(sum-sum2));
            if(d%2==0)ans++;
        }
        return ans==-1?0:ans;
    }
};