class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = INT_MIN;
        for(int i=0; i<n-1; i++){
            if(colors[i]!=colors[n-1])ans=max(ans, max(i, n-i-1));
        }
        return ans;
    }
};