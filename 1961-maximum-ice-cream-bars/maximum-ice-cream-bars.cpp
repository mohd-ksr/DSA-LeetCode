class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans=0;
        int cost=0;
        for(int n:costs){
            if(cost<coins && (coins-cost)>=n){
                ans++;
                cost+=n;
            }
        }
        return ans;
    }
};