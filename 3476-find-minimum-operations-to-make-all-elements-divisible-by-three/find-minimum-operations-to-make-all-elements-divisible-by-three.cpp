class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        for(int x:nums)if(x%3==0)cnt++;
        return nums.size()-cnt;
    }
};
// Time Complexity O(n)