class Solution {
private:
    int ds(int n){
        if(n<=0)return 0;
        return n%10+ds(n/10);
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(i==ds(nums[i]))return i;
        }
        return -1;
    }
};