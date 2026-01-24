class Solution {
private:   
    int isPossible(vector<int>& nums, int div, int threshold){
        int sum = 0;
        for(auto &n:nums){
            sum += ceil((1.0*n)/div);
        }
        return sum<=threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1, e = *max_element(nums.begin(), nums.end());
        while(s<e){
            int mid = s+(e-s)/2;
            if(isPossible(nums, mid, threshold)){
                e=mid;
            }
            else s=mid+1;
        }
        return e;
    }
};