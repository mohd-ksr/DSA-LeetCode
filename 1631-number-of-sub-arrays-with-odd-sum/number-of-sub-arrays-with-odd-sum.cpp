class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        int const mod = 1e9+7;
        int e=1, o=0;
        int sum=0;
        int ans=0;
        for(auto &num:nums){
            sum+=num;
            if(sum%2==0){
                ans = (ans+o)%mod;
                e++;
            }
            else{
                ans=(ans+e)%mod;
                o++;
            }
            sum=sum%2;
        }
        return ans;
    }
};