class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.rbegin(), maximumHeight.rend());
        for(auto t:maximumHeight)cout<<t<<" ";
        cout<<endl;
        int n = maximumHeight.size();
        long long ans = maximumHeight[0];
        for(int i=1; i<n; i++){
            maximumHeight[i]=min(maximumHeight[i], maximumHeight[i-1]-1);
            if(maximumHeight[i]<1)return -1;
            ans+=maximumHeight[i];
        }
        return ans;
    }
};