class Solution {
private:    
    int r,c;
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        this->r = grid.size();
        this->c = grid[0].size();
        vector<int>nums;
        for(auto rows:grid){
            for(auto el:rows){
                nums.push_back(el);
            }
        }
        sort(nums.begin(), nums.end());
        int target;
        if((r*c)%2==1){
            target = nums[(r*c)/2];
        }
        else{
            target = nums[((r*c)/2)-1];
        }

        int ans=0;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                int need = abs(grid[i][j]-target);
                if(need%x!=0)return -1;
                ans+=(need/x);
            }
        }
        return ans;
    }
};