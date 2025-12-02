class Solution {
private:
    bool p(int n, vector<int>& price, int k){
        k--;
        int temp = price[0];
        for(int i=1; i<price.size(); i++){
            if(price[i]-temp>=n){
                temp=price[i];
                if(--k==0)return true;
            }
        }
        return false;
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int s=0, e=price[price.size()-1]-price[0];
        while(s<=e){
            int mid = s+(e-s)/2;
            if(p(mid,price,k))s=mid+1;
            else e=mid-1;
        }
        return e;
    }
};
// Time Complexity O(Nlogn)