class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        while(n%4==0)n/=4;
        return n==1;
    }
};
// Time complexity O(log4​(n))
// Space complexity O(1)