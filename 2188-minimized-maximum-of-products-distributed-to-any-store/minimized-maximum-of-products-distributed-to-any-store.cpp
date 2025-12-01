class Solution {
private:
    bool canDist(int k, int n, vector<int>& quantities){
        int t=0;
        for(int q:quantities){
            t+=ceil((double)q/(double)k);
            if(t>n)return false;
        }
        return true;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int s=1, e=*max_element(quantities.begin(),quantities.end());
        while(s<e){
            int mid = s+(e-s)/2;
            if(canDist(mid, n, quantities))e=mid;
            else s=mid+1;
        }
        return e;
    }
};