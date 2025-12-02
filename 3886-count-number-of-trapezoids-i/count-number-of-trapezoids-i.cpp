class Solution {
private:
    long long fn(long long n){
        if(n<=1)return 0;
        return n*(n-1)/2;
    }
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,long long>mapp;
        for(auto &p:points){
            mapp[p[1]]++;
        }
        const long long MOD = 1000000007LL;
        long long  ans = 0;

        long long sum = 0;
        long long  squarSum = 0;
        for(auto &it:mapp){
            long long temp = fn(it.second);
            sum=(sum+temp)%MOD;
            squarSum=(squarSum + (temp*temp)%MOD)%MOD;
        }
        const long long inv2 = 500000004LL;
        ans = ((sum*sum)%MOD - squarSum+MOD)*inv2%MOD;
        return (int)ans;
    }
};