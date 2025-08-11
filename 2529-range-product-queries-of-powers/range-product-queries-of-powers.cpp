class Solution {
private:
    vector<int> createPower(int n){
        vector<int>powers; int ind=0;
        while(n){
            if(n&1)powers.push_back(1<<ind);
            ind++;
            n/=2;
        }
        return powers;
    }
    long long powMod(long long base, long long exp, int mod) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD=1e9+7;
        vector<int>powers=createPower(n);
        int size=powers.size();
        
        vector<long long> prefix(size + 1, 1);
        for (int i = 0; i < size; i++) {
            prefix[i + 1] = (prefix[i] * powers[i]) % MOD;
        }

        vector<int>ans;
        for(auto &q:queries){
            int l=q[0],r=q[1];
            long long product=prefix[r+1]*1LL*powMod(prefix[l],MOD-2,MOD)%MOD;
            ans.push_back(product);
        }
        return ans;
    }
};

// TC: O(log n + m)
// SC: O(log n + m)