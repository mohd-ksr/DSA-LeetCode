class Solution {
public:
    int countPrimes(int n) {
        vector<bool>isPrime(n+1, true);
        int ans = 0;
        for(int i=2; i*i<n; i++){
            if(isPrime[i]){
                for(int j = i*i; j<n; j+=i){
                    isPrime[j]=false;
                }
            }
        }
        for(int i=2; i<n; i++)if(isPrime[i])ans++;
        return ans;
    }
};