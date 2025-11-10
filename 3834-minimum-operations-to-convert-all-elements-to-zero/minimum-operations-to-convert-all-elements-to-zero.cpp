class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        vector<int>s;
        for(int n:nums){
            while(!s.empty() && s.back()>n)s.pop_back();
            if(n==0)continue;
            if(s.empty() || s.back() < n){
                ans++;
                s.push_back(n);
            }
        }
        return ans;
    }
};
// Time Complexity O(n)