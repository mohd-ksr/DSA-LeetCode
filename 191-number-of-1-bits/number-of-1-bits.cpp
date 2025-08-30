class Solution {
public:
    int hammingWeight(int n) {
        // Brian Kernighan’s Algo
        int ans=0;
        while(n){
            n&=(n-1);
            ans++;
        }
        return ans;
    }
};