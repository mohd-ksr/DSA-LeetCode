class Solution {
private:
    bool p(int n, vector<int>& candies, long long k){
        if(n==0)return true;
        long long temp = 0;
        for(auto &c:candies)temp+=(c/n);
        return temp>=k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int s=0, e=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(p(mid,candies,k)){
                ans=mid;
                s=mid+1;
            }
            else e=mid-1;
        }
        return ans;
    }
};