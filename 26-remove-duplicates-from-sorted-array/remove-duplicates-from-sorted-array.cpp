class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s;
        for(auto n:nums){
            s.insert(n);
        }
        int ind=0;
        for(auto &it:s){
            nums[ind++]=it;
        }
        return s.size();
        
    }
};
// Time Complexity O(n log n)
// Space Complexity O(n)