class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals), [](vector<int>&a, vector<int>&b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        int ans=1;
        int ptr1=0;
        int n = intervals.size();
        for(int i=1; i<n; i++){
            if(intervals[i][0] >= intervals[ptr1][0] && intervals[i][0] <= intervals[ptr1][1] && intervals[i][1]>=intervals[ptr1][0] && intervals[i][1]<=intervals[ptr1][1])continue;
            ptr1=i;
            ans++;
        }
        return ans;
    }
};