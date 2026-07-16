class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        vector<int>prefixGcd(n);
        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], maxi);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long sum = 0;
        int s=0, e=n-1;
        while(s<e){
            sum+=gcd(prefixGcd[s++], prefixGcd[e--]);
        }
        return sum;
    }
};