class Solution {
private:
    bool solve(int n, vector<int>& arr, int start, vector<int>&vis){
        if(start>=n || start<0)return false;
        if(vis[start])return false;
        if(arr[start]==0)return true;
        vis[start]=true;
        return solve(n, arr, start+arr[start], vis) || solve(n, arr, start-arr[start], vis);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int>vis(n, false);
        return solve(n, arr, start, vis);
    }
};