class Solution {
private:
    bool solve(vector<int>& arr, int start, vector<bool>&vis){
        if(start>= arr.size() || start<0) return false;
        if(vis[start]) return false;
        if(arr[start]==0) return true;

        vis[start]=true;
        bool left = solve(arr, start-arr[start], vis);
        bool right = solve(arr, start+arr[start], vis);

        return left || right;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool>vis(arr.size(), false);
        return solve(arr, start, vis);
    }
};