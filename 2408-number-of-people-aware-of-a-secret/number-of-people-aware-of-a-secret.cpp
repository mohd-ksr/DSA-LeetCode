class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // queue<int>q;
        // q.push(1);
        // for(int i=2; i<=n; i++){
        //     queue<int>temp;
        //     while(!q.empty()){
        //         int front = q.front();
        //         q.pop();
        //         if(i-front>=forget)continue;
        //         else if(i-front>=delay){
        //             temp.push(i);
        //             temp.push(front);
        //         }
        //         else temp.push(front);
        //     }
        //     q=temp;
        // }
        // return q.size();

        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0), prefix(n + 2, 0);
        
        dp[1] = 1;  
        prefix[1] = 1;

        for (int i = 2; i <= n; i++) {

            int left = max(1, i - forget + 1);
            int right = i - delay;
            if (right >= left) {
                dp[i] = (prefix[right] - prefix[left - 1] + MOD) % MOD;
            }
            prefix[i] = (prefix[i - 1] + dp[i]) % MOD;
        }

        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1) ans = (ans + dp[i]) % MOD;
        }
        return (int)ans;
    }
};
// time complexity O(n)