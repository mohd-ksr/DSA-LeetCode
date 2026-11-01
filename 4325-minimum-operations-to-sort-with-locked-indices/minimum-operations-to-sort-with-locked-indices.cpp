class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n-i-1; j++){
                if(nums[j] > nums[j+1]){
                    if(locked[j]==1){
                        locked[j]=0;
                        k--;
                        ans++;
                    }
                    if(locked[j+1]==1){
                        locked[j+1]=0;
                        k--;
                        ans++;
                    }
                    if(k<0)return -1;
                    ans++;
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        return ans;
    }
};