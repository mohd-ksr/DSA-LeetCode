class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0,c=0,n=nums.size();
        for(int i=0; i<n-count; i++){
            if(nums[i]==val){
                for(int j=n-1-count; j>i; j--){
                    if(nums[j]!=val){
                        swap(nums[i],nums[j]);
                        count++;
                        break;
                    }
                }
                c++;
            }
        }
    
        return n-c;
    }
};
// Time Complexity O(n²)
// Space Complexity O(1)