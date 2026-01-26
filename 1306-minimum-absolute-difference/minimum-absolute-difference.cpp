class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n =arr.size();
        int minDiff = INT_MAX;
        sort(arr.begin(), arr.end());

        for(int i=1; i<n; i++){
            minDiff = min(minDiff, arr[i]-arr[i-1]);
        }

        vector<vector<int>>ans;
        for(int i=1; i<n; i++){
            if((arr[i]-arr[i-1])==minDiff)ans.push_back({arr[i-1], arr[i]});
        }

        return ans;
    }
};
// Time Complexity O(n)
// Space Complexity O(n)