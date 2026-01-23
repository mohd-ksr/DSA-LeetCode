class Solution {
private:
    double solve(double x, long long n){
        if(n==0)return 1.0;
        double half = solve(x, n/2);
        if(n%2==0)return half*half;
        return half*half*x;
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        if(n<0){
            x = 1.0/x;
            N=-N;
        }
        return solve(x,N);
    }
};