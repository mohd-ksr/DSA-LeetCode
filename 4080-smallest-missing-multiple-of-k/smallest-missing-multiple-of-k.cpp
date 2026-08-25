class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s(nums.begin(), nums.end());
        int mul=k;
        while(true){
            if(s.find(mul)==s.end())return mul;
            mul+=k;
        }
        return 0;
    }
};