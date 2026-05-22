class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n==0)return 0;
        vector<pair<int, double>>arr(n);
        for(int i=0; i<n; i++){
            double time = (double)(target-position[i])/speed[i];
            arr[i] = {position[i],time};
        }
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        double maxtime = arr[0].second;
        int ans = 1;
        for(int i=1; i<n; i++){
            if(maxtime < arr[i].second){
                maxtime = arr[i].second;
                ans++;
            }
        }
        return ans;
    }
};