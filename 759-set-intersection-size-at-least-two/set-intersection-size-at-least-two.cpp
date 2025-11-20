class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>&A, vector<int>&B){
            return (A[1]==B[1])?A[0]>B[0]:A[1]<B[1];
        });
        int cnt  = 2;
        int n = intervals.size();
        int b = intervals[0][1], a = b-1;
        for(int i=1; i<n; i++){
            int L = intervals[i][0], R = intervals[i][1];
            if(a>=L)continue;
            bool temp = L>b;
            cnt += 1 + temp;
            a = temp?R-1:b;
            b = R;
        }
        return cnt;
    }
};
// Time complexity O(nlogn)