class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int ans = 0;
        int ind=0;
        while(n){
            int bit = n&1;
            bit = !bit;
            if(bit==1)ans+=pow(2, ind);
            n>>=1;
            ind++;
        }
        return ans;
    }
};