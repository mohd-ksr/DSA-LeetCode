class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool hasNonZeroNumber = false;
        int x = 0;
        for(auto num:nums){
            x^=num;
            if(num!=0)hasNonZeroNumber=true;
        }
        if(x!=0)return nums.size();
        return hasNonZeroNumber? nums.size()-1:0;
    }
};