class Solution {
public:
    int maxProduct(int n) {
        int maxi = -1;
        int secondMaxi = -1;
        while(n){
            int d = n%10;
            if(d>=maxi){
                secondMaxi = maxi;
                maxi = d;
            }
            else if(d>=secondMaxi){
                secondMaxi = d;
            }
            n/=10;
        }
        return maxi*secondMaxi;
    }
};