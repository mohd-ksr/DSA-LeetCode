class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int k=0; k<=60; k++){
            long long target = (long long)num1 - 1LL*k*num2;
            if(target<k)continue;
            int bits = __builtin_popcountll(target);
            if(bits<=k && k<=target)return k;
        }
        return -1;
    }
};
// time complexity O(1)
// space complexity O(1)
