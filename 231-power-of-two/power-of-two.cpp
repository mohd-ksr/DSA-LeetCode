class Solution {
public:
    bool isPowerOfTwo(int n) {
        // O(log(n)) solution...
        // int c=0;
        // while(n){
        //     if(n>=INT_MAX || n<0)return false;
        //     if(n&1==1)c++;
        //     n=n>>1;
        // }
        // return c==1;

        // O(1) solution..

        
        return n<1?false:(n&(n-1))==0?true:false;
    }
};