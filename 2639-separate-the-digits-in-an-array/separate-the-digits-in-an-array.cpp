class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        string temp = "";
        for(auto num:nums){
            temp+=to_string(num);
        }
        int n = temp.size();
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            ans[i] = (temp[i]-'0');
        }
        return ans;
    }
};