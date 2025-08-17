class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0 || n>=k+maxPts)return 1.0;
        vector<double> dp(n+1);
        dp[0]=1.0;
        double windowSize=1.0, result=0.0;
        for(int i=1; i<=n; i++){
            dp[i]=windowSize/maxPts;
            if(i<k)windowSize+=dp[i];
            else result+=dp[i];
            if(i>=maxPts)windowSize-=dp[i-maxPts];
        }
        return result;
    }
};
// Time Complexity O(n)
// Space Complexity O(n)