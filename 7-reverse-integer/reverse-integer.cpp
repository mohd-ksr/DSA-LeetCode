class Solution {
public:
    int reverse(int n) {
        int ans=0;
        while(n){
            if(ans>INT_MAX/10 || ans<INT_MIN/10) return 0;
            ans=ans*10+(n%10);
            n/=10;
        }
        return ans;
    }
};
// Time Complexity O(log₁₀(n))
// Space Complexity O(1)