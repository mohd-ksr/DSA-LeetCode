class Solution {
private:
    int sumOfDig(int n){
        if(n<=9)return n;
        return (n%10) + sumOfDig(n/10);
    }
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(auto num:nums){
            ans = min(ans, sumOfDig(num));
        }
        return ans;
    }
};