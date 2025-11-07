class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long>prefix(n+1,0);
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i]+stations[i];
        }

        vector<long long>power(n);
        for(int i=0; i<n; i++){
            int left = max(0, i-r);
            int right = min(n, i+r+1);
            power[i] = prefix[right] - prefix[left];
        }

        auto canAchieve = [&](long long minPower) -> bool{
            vector<long long>added(n, 0);
            long long used = 0;
            long long windowAdd = 0;
            for(int i=0; i<n; i++){
                if(i-r-1 >= 0) windowAdd -= added[i-r-1];
                long long total = power[i] + windowAdd;
                if(total < minPower){
                    long long need = minPower - total;
                    if(used + need > k)return false;
                    used += need;
                    int pos  = min(n-1, i+r);
                    added[pos]+=need;
                    windowAdd+=need;
                }
            }
            return true;
        };

        long long low = 0, high = *max_element(power.begin(), power.end())+k;
        long long ans = 0;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(canAchieve(mid)){
                ans=mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};









