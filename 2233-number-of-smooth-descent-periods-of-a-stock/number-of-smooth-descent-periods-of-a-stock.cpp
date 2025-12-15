class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 1;
        long long streak = 1;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]==prices[i-1]-1)streak++;
            else streak=1;
            ans+=streak;
        }
        return ans;
    }
};