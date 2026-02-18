class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool tog = n&1;
        n>>=1;
        while(n){
            bool temp = tog;
            tog = n&1;
            n>>=1;
            if(temp==tog)return false;
        }
        return true;
    }
};