class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1)return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(auto &n:nums)cout<<n<<" ";
        int mini = INT_MAX;
        int i=0;
        k--;
        while(k<n){
            mini=min(mini, (nums[k]-nums[i]));
            k++;
            i++;
        }
        return mini;
    }
};

// Time Complexity O(nlogn + n)