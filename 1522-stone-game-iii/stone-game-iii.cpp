class Solution {
public:
    string stoneGameIII(vector<int>& sv) {
        int n = size(sv) ;
        int dp[3] = {sv[n-1],0,0} ;

        for(int i = n-2 ; i>=0 ; i--){
            int res = sv[i] - dp[0] ;
            res = max(res,sv[i]  + sv[i + 1] - dp[1]) ;
            if(i + 2 < n) res = max(res,sv[i]  + sv[i + 1] + sv[i + 2] - dp[2]) ;
            
            dp[2] = dp[1] ; dp[1] = dp[0] ; dp[0] = res ;
        }

        if(dp[0] > 0) return "Alice" ;
        else if(dp[0] == 0) return "Tie" ;
        return "Bob" ;
    }
};