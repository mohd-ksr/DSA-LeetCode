class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0;
        int cnd1 = 0, cnd2 = 1;
        for(auto &num:nums){
            if(num==cnd1)c1++;
            else if(num==cnd2)c2++;
            else if(c1==0){
                c1=1;
                cnd1=num;
            }
            else if(c2==0){
                c2=1;
                cnd2=num;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(auto &num:nums){
            if(num==cnd1)c1++;
            if(num==cnd2)c2++;
        }
        int n=nums.size();
        vector<int>ans;
        if(c1>n/3)ans.push_back(cnd1);
        if(c2>n/3)ans.push_back(cnd2);
        return ans;
    }
};