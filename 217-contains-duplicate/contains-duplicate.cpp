class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>s;
        for(auto &n: nums){
            s.insert(n);
        }
        return !(s.size()==nums.size());
    }
};
// Time Complexity O(n)
// Space Complexity O(n)