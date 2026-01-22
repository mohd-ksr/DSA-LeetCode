class Solution {
private:
    bool check(vector<int>&nums){
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]>nums[i])return false;
        }
        return true;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        while(!check(nums) && nums.size()>1){
            int i=0,j=1;
            int sum=nums[0]+nums[1];
            for(int k=0; k<nums.size()-1; k++){
                int temp=nums[k]+nums[k+1];
                if(temp<sum){
                    i=k; 
                    j=k+1;
                    sum=temp;
                }
            }
            nums[i]=sum;
            for(int k=j; k<nums.size()-1; k++){
                nums[k]=nums[k+1];
            }
            nums.pop_back();
            count++;
        }
        return count;
    }
};

// time complexityO(n²)