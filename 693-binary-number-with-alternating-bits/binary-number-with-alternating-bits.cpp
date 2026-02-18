class Solution {
public:
    bool hasAlternatingBits(int n) {
        int temp = n>>1;
        unsigned int x = (temp ^ n);
        return (x & (x+1))==0;
    }
};