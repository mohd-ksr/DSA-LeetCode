class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int empty = 0;
        int full = numBottles;
        while(full>0){
            ans+=full;
            empty+=full;
            full=0;
            full = empty / numExchange;
            empty = empty % numExchange;
        }
        return ans;
    }
};
// Time complexity O(Log(N))
