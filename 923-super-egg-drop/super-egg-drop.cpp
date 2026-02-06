class Solution {
private:
    int solve(int eggs, int floors, vector<vector<int>>&dp){
        if(floors<=1 || eggs==1)return floors;
        if(dp[eggs][floors]!=-1)return dp[eggs][floors];

        // int ans = INT_MAX;
        // for(int i=1; i<=floors; i++){
        //     int b,nb;
        //     if(dp[eggs-1][i-1]!=-1){
        //         b=dp[eggs-1][i-1];
        //     }
        //     else{
        //         b=solve(eggs-1, i-1, dp);
        //         dp[eggs-1][i-1]=b;
        //     }

        //     if(dp[eggs][floors-i]!=-1){
        //         nb=dp[eggs][floors-i];
        //     }
        //     else{
        //         nb=solve(eggs, floors-i, dp);
        //         dp[eggs][floors-i]=nb;
        //     }

        //     ans = min(ans, 1+max(b, nb));
        // }

        int s=0, e=floors, ans=INT_MAX;
        while(s<=e){
            int mid = s+(e-s)/2;

            // int b = solve(eggs-1, mid-1, dp);
            // int nb = solve(eggs, floors-mid, dp);

            int b,nb;
            if(dp[eggs-1][mid-1]!=-1){
                b=dp[eggs-1][mid-1];
            }
            else{
                b = solve(eggs-1, mid-1, dp);
                dp[eggs-1][mid-1]=b;
            }

            if(dp[eggs][floors-mid]!=-1){
                nb=dp[eggs][floors-mid];
            }
            else{
                nb = solve(eggs, floors-mid, dp);
                dp[eggs][floors-mid]=nb;
            }
            
            if(b<nb){
                s = mid+1;
            }
            else{
                e = mid-1;
            }

            ans = min(ans, 1+max(b, nb));
        }
        return dp[eggs][floors]=ans;
    }
public:
    int superEggDrop(int eggs, int floors) {
        vector<vector<int>>dp(eggs+1, vector<int>(floors+1, -1));
        return solve(eggs, floors, dp);
    }
};