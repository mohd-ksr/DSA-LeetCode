class Solution {
private:
    bool solve(int s, int e, int p1, int p2, bool isP1,vector<int>& nums){
        if(s>e){
            return p1>=p2;
        }
        bool start, end;
        if(isP1){
            start = solve(s+1, e, p1+nums[s], p2, false, nums);
            end = solve(s, e-1, p1+nums[e], p2, false, nums);
            return start || end;
        }
        else{
            start = solve(s+1, e, p1, p2+nums[s], true, nums);
            end = solve(s, e-1, p1, p2+nums[e], true, nums);
            return start && end;
        }
        
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        return solve(0, nums.size()-1, 0, 0, true, nums);
    }
};