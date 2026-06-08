class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int l=0;
        int g=0;
        int e=0;
        for(auto num:nums){
            if(num<pivot)l++;
            else if(num>pivot)g++;
            else e++;
        }
        vector<int>ans(n);
        int i=0, j=l, k=l+e;
        for(auto num:nums){
            if(num<pivot)ans[i++]=num;
            else if(num>pivot)ans[k++]=num;
            else ans[j++]=num;
        }
        return ans;
    }
};