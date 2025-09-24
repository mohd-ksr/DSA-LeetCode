class Solution {
private:
    int getPivot(vector<int>nums){
        int n=nums.size();
        int s=0; int e=n-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return s;
    }
    int binarySearch(vector<int>nums, int s, int e, int k){
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==k)return mid;
            if(nums[mid]>k){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        // int p=getPivot(nums);
        // int n=nums.size();
        // if(target>=nums[p] && target<=nums[n-1]){
        //     return binarySearch(nums,p,n-1,target);
        // }
        // else{
        //     return binarySearch(nums,0,p-1,target);
        // }
        int n=nums.size();
        int s=0,e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target)return mid;
            if(nums[s]<=nums[mid]){
                if(nums[s]<=target && target<=nums[mid])e=mid-1;
                else s=mid+1;
            }
            else{
                if(nums[mid]<=target && target<=nums[e])s=mid+1;
                else e=mid-1;
            }
        }
        return -1;
    }
};
// Time Complexity O(log n)
// Space Complexity O(1)