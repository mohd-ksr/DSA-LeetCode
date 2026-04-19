class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int val = nums1[i];
            int s = i, e = m-1;
            int ind=-1;
            while(s<=e){
                int mid = s+(e-s)/2;
                if(nums2[mid]>=val){
                    ind=mid;
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
            if(ind!=-1)ans=max(ans,ind-i);
        }
        return ans;
    }
};