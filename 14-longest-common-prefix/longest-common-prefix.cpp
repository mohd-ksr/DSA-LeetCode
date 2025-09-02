class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ans="";
        sort(strs.begin(),strs.end());
        for(int i=0; i<strs[0].size(); i++){
            if(strs[0][i]!=strs[strs.size()-1][i])break;
            ans+=strs[0][i];
        }
        return ans;
    }
};
// Time complexity O(nlogn) due to sorting
// Space Complexity O(1);