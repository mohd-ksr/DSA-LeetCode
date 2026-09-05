class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>maxi(n);
        vector<int>mini(n);
        maxi[0]=nums[0];
        int m = nums[0];
        for(int i=1; i<n; i++){
            m=max(m, nums[i]);
            maxi[i]=m;
        }
        mini[n-1]=nums[n-1];
        int mi = nums[n-1];
        for(int i=n-1; i>=0; i--){
            mi=min(mi, nums[i]);
            mini[i]=mi;
        }

        for(int i=0; i<n; i++){
            if(maxi[i]-mini[i]<=k)return i;
        }
        return -1;
    }
};