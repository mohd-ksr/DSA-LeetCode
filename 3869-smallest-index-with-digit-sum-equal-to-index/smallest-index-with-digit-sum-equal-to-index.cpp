class Solution {
private:
    int ds(int n){
        return n!=0 ? n%10+ds(n/10) : 0;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(i==ds(nums[i]))return i;
        }
        return -1;
    }
};