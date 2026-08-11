class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]==nums[i-1]+1)sum+=nums[i];
            else break;
        }
        int maxi = *max_element(nums.begin(), nums.end());
        if(sum>maxi)return sum;
        for(int x=sum; x<maxi; x++){
            bool isP = false;
            for(auto num:nums){
                if(x==num)isP=true;
            }
            if(!isP)return x;
        }
        return maxi+1;
    }
};