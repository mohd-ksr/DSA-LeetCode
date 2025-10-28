class Solution {
private:
    bool sim(vector<int>nums, int start, int dir){
        int n = nums.size();
        int curr = start;
        while(curr>=0 && curr<=n-1){
            if(nums[curr]==0){
                curr += dir;
            }
            else{
                nums[curr]--;
                dir = -dir;
                curr += dir;
            }
        }
        for(int x:nums)if(x!=0)return false;
        return true;
    }
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
         for(int i=0; i<n; i++){
            if(nums[i]==0){
                if(sim(nums,i,1))res++;
                if(sim(nums,i,-1))res++;
            }
         }
         return res;
    }
};