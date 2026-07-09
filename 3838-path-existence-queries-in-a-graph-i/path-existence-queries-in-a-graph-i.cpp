class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>mapp(n);
        mapp[0]=1;
        for(int i=1; i<n; i++){
            if(abs(nums[i]-nums[i-1])<=maxDiff){
                mapp[i]=mapp[i-1];
            }
            else{
                mapp[i]=mapp[i-1]+1;
            }
        }
        int m = queries.size();
        vector<bool>ans(m);
        for(int i=0; i<m; i++){
            int ui = queries[i][0];
            int vi = queries[i][1];
            ans[i] = (mapp[ui]==mapp[vi]);
        }
        return ans;

    }
};