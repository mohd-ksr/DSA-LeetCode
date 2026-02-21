class Solution {
private:
    int countBits(int n){
        int count=0;
        while(n){
            count+=(n&1);
            n>>=1;
        }
        return count;
    }
    bool isPrime(int n){
        if(n<=1)return false;
        else if(n==2 || n==3)return true;
        else if(n%2==0 || n%3==0)return false;

        for(int i=5; i*i<=n; i+=2){
            if(n%i==0)return false;
        }
        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left; i<=right; i++){
            if(isPrime(countBits(i)))count++;
        }
        return count;
    }
};