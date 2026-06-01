class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size();
        int g = n/3;
        int ind=n-1;
        long long minCost = 0;
        while(g--){
            minCost+=(cost[ind]+cost[ind-1]);
            ind-=3;
        }
        while(ind>=0){
            minCost+=cost[ind--];
        }
        return minCost;
    }
};