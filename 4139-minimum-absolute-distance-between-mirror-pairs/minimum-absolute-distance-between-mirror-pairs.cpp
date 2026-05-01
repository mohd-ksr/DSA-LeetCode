class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int>mapp;
        int ans = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            int r = stoi(s);

            if(mapp.count(nums[i])){
                ans = min(ans, i-mapp[nums[i]]);
            }
            mapp[r]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};