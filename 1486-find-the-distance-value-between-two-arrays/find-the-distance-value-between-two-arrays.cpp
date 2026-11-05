class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for(auto a1:arr1){
            bool ok = true;
            for(auto a2:arr2){
                if(abs(a1-a2) <= d){
                    ok = false;
                    break;
                }
            }
            ans += ok;
        }
        return ans;
    }
};