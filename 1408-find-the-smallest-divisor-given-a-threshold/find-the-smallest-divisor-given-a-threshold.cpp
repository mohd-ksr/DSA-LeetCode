class Solution {
private:
    bool isPossible(vector<int>& nums, int d, int th){
        int res = 0;
        for(int n:nums){
            res+=ceil((double)n/(double)d);
        }
        return res<=th;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1, e = *max_element(nums.begin(), nums.end());
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPossible(nums,mid,threshold))e=mid-1;
            else s = mid+1;
        }
        return s;
    }
};