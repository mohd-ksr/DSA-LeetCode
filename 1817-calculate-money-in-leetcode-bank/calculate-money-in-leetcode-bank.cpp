class Solution {
public:
    int totalMoney(int n) {
        int completeWeek = n/7;
        int remainingDays = n%7;
        int countWeek = 1;
        long long ans = 0;
        while(countWeek <= completeWeek){
            ans+=(countWeek*7 + 21);
            countWeek++;
        }
        ans+=(countWeek*remainingDays + remainingDays*(remainingDays-1)/2);
        return ans;
    }
};
// Time complexity O(1)