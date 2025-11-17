class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n0=0,n1=0,n2=0;
        for(auto n:nums){
            if(n==0)n0++;
            else if(n==1)n1++;
            else n2++;
        }
        for(int i=0; i<n0; i++){
            nums[i]=0;
        }
        for(int i=0; i<n1; i++){
            nums[n0+i]=1;
        }
        for(int i=0; i<n2; i++){
            nums[n0+n1+i]=2;
        }
    }
};
// Time Complexity O(n)