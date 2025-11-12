class Solution {
private:
    int gcd(int a, int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
public:
    int minOperations(vector<int>& nums) {
        int num1 = 0;
        int g = 0;
        int n = nums.size();
        for(int x:nums){
            if(x==1)num1++;
            g = gcd(g,x);
        }
        if(num1>0)return n-num1;
        if(g>1)return -1;

        int min_len = n;
        for(int i=0; i<n; i++){
            int g=0;
            for(int j=i; j<n; j++){
                g=gcd(g, nums[j]);
                if(g==1){
                    min_len=min(min_len, j-i+1);
                    break;
                }
            }
        }
        return min_len+n-2;
    }
};