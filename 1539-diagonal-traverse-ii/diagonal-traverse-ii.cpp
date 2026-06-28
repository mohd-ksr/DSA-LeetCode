class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){
                pq.push({i+j, -i, j});
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            auto [sum, r, c] = pq.top();
            r=-r;
            ans.push_back(nums[r][c]);
            pq.pop();
        }
        return ans;
    }
};