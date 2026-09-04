class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>mini(n);
        mini[n-1]=nums[n-1];
        int mi = nums[n-1];
        for(int i=n-1; i>=0; i--){
            mi=min(mi, nums[i]);
            mini[i]=mi;
        }
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
            if(maxi-mini[i]<=k)return i;
        }
        return -1;
    }
};