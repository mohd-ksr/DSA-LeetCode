class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        vector<int>ans;
        while(s<=e){
            int ls=nums[s]*nums[s];
            int rs=nums[e]*nums[e];
            if(ls>rs){
                ans.push_back(ls);
                s++;
            }
            else{
                ans.push_back(rs);
                e--;
            }
        }
        for(int i=0; i<(nums.size())/2;i++){
            swap(ans[i],ans[nums.size()-i-1]);
        }
        return ans;
    }
};
// Time Complexity O(n)
// Space Complexity O(n)