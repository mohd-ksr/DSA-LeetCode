class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n,1), right(n,1);
        for(int i=0; i<n;i++){
            if(i-1>=0){if(nums[i]>nums[i-1])left[i]=left[i-1]+1;}
            if(n-i-2>=0){if(nums[n-i-2]>nums[n-i-1])right[n-i-2]=right[n-i-1]+1;}
        }
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=max(left[i], right[i]);
        }
        return sum;
    }
};