class Solution {
private:
    int lowerBound(vector<int>&nums,int k){
        int ans=nums.size();
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]>=k){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
    int upperBound(vector<int>&nums,int k){
        int ans=nums.size();
        int s=0,h=nums.size()-1;
        while(s<=h){
            int mid=s+(h-s)/2;
            if(nums[mid]>k){
                ans=mid;
                h=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // vector<int>ans(2,-1);
        // if(nums.size()<=0)return ans;
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i]==target && ans[0]==-1){
        //         ans[0]=ans[1]=i;
        //     }
        //     if(nums[i]==target) ans[1]=i;
        // }
        // return ans;


        // int s=0,e=nums.size()-1;
        // int ind=-1;
        // while(s<e){
        //     int mid=s+(e-s)/2;
        //     if(nums[mid]==target){
        //         ind=mid;
        //         e=mid;
        //     }
        //     else if(nums[mid]<target)s=mid+1;
        //     else e=mid-1;
        // }
        // ans[0]=ind;

        // s=0,e=nums.size()-1;
        // while(s<e){
        //     int mid=s+(e-s)/2;
        //     if(nums[mid]==target){
        //         ind=mid;
        //         s=mid+1;
        //     }
        //     else if(nums[mid]>target)e=mid-1;
        //     else s=mid+1;
        // }
        // ans[1]=ind;
        // return ans;

        int lb=lowerBound(nums,target);
        if(lb==nums.size() || nums[lb]!=target)return {-1,-1};
        return {lb,upperBound(nums,target)-1};
    }
};
// Time Complexity O(log n)
// Space Complexity O(1)