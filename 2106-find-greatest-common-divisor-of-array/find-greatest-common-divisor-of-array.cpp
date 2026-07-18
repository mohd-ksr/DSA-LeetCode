class Solution {
private:
    int gcd(int a, int b){
        if(b==0)return a;
        return gcd(b, a%b);
    }
public:
    int findGCD(vector<int>& nums) {
        int mn=100000, mx=0;
        for(int num:nums){
            if(num>mx)mx=num;
            if(num<mn)mn=num;
        }
        return gcd(mx, mn);
    }
};