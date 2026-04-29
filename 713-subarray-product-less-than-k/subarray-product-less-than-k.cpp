class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)return 0;
        int n = nums.size();
        int i=0, j=0, cnt=0;
        int prod = 1;
        while(j<n){
            prod *= nums[j];
            while(prod>=k){
                prod/=nums[i];
                i++;
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
};