class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int xc=x;
        int ans=0;
        while(xc){
            int d=xc%10;
            if(ans<INT_MAX/10 && ans>INT_MIN/10){
                ans=ans*10 + d;
            }
            xc/=10;
        }
        if(ans==x) return true;
        return false;
    }
};
// Time Complexity O(log₁₀(x))
// Space Complexity O(1)