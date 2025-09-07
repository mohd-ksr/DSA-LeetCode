class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans(n);
        int i = 0;
        for(i=0; i<n/2; i++){
            ans[i] = i+1;
            ans[n-i-1] = -(i+1);
        }
        if(n&1)ans[i]=0;
        return ans;
    }
};
// Time complexity O(n)
// Space complexity O(1)