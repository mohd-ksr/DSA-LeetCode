class Solution {
private:
    double power(double x, long long N){
        if(N==0)return 1.0;
        double half=power(x,N/2);
        if(N%2==0)return half * half;
        else return half*half*x;
    }
public:
    double myPow(double x, int n) {
        long long N=n;
        if(N<0){
            x=1/x;
            N=-N;
        }
        return power(x,N);
    }
};

// Time Complexity O(log n)
// Space Complexity O(log n)