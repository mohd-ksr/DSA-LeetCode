class Solution {
private:    
    int getPivot(vector<int>&nums, int s, int e){
        if(s>=e)return s;
        int mid = s+(e-s)/2;
        if(nums[mid]>=nums[0]){
            return getPivot(nums, mid+1, e);
        }
        else{
            return getPivot(nums,s, mid);
        }
    }
    int BS(vector<int>&nums, int s, int e, int &t){
        if(s>e)return -1;
        int mid = s+(e-s)/2;
        if(nums[mid]==t)return mid;
        else if(nums[mid]>t) return BS(nums, s, mid-1, t);
        else return BS(nums, mid+1, e, t);
    }
public:
    int search(vector<int>& nums, int t) {
        int n = nums.size();
        if (n == 0) return -1;

        int p = getPivot(nums, 0, n-1);
        if(t>=nums[p] && t<=nums[n-1]){
            return BS(nums, p, n-1, t);
        }
        return BS(nums, 0, p-1, t);
    }
};