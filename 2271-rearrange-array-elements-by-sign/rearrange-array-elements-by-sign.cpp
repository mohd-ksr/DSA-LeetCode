class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>neg,pos;
        for(int &num:nums){
            if(num<0)neg.push_back(num);
            else pos.push_back(num);
        }

        int p=0, np=0;
        for(int i=0; i<n; i++){
            if(i%2==0)nums[i]=pos[p++];
            else nums[i]=neg[np++];
        }

        return nums;

    }
};