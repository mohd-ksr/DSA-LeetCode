class Solution {
private:
    int smallestFact(int n){
        for(int i=2; i*i<=n; i++){
            if(n%i==0)return i;
        }
        return 1;
    }
public:
    long long minimumMaxValue(int n, int index, int value) {
        if(value==1)return -1;
        long long fact = smallestFact(value);
        if(smallestFact(value)==1){
            if(index!=0)return -1;
            else return (long long)value*2 + (long long)(n-2)*2;
        }
        long long numOfFact = 1;
        long long temp = value - fact;
        numOfFact+=(temp)/2 - 1;
        if(numOfFact<index)return -1;
        // 0 1 2 3 4 5 6
        // 6 8 10 12 15
        value += fact;
        return (long long)value + (long long)(n-index-2)*2;
        
    }
};