class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0)return 0;
        int temp = 1;
        int k = 0;
        while(temp*2 <= n){
            temp *= 2;
            k++;
        }
        return (1<<(k+1)) - 1 - minimumOneBitOperations(n^temp);
    }
};