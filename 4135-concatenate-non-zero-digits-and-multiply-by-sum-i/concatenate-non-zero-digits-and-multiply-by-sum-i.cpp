class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        int i = 0;
        while(n){
            int ld = n%10;
            n/=10;
            if(ld==0)continue;
            sum+=ld;
            x = x + ld*pow(10,i);
            i++;
        }
        return sum*x;
    }
};