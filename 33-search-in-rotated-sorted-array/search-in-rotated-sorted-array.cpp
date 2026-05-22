class Solution {
private:
    int getP(vector<int>& nums){
        int s=0, e = nums.size()-1;
        while(s<e){
            int mid = s+(e-s)/2;
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return s;
    }
    int bs(vector<int>& nums, int target, int s, int e){
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target){
                e=mid-1;
            }
            else s=mid+1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int p = getP(nums);
        if(target>=nums[p] && target<=nums[n-1]){
            return bs(nums, target, p, n-1);
        }
        else{
            return bs(nums, target, 0, p-1);
        }
    }
};