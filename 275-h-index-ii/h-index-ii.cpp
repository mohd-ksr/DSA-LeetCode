class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int s=0, e=n-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(citations[mid]<(n-mid))s=mid+1;
            else e=mid-1;
        }
        return n-s;
    }
};
// Time Complexity O(logn)