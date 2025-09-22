class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // unordered_map<int, int> freq;
        // for(auto n: nums){
        //     freq[n]++;
        // }
        // int maxi = 0;
        // for(auto it: freq){
        //     maxi = max(maxi, it.second);
        // }

        // int count = 0;
        // for(auto it: freq){
        //     if(it.second==maxi){
        //         count++;
        //     }
        // }

        // return count*maxi;
        vector<int>freq(101);
        int maxi=0, cnt=0,ans=0;
        for(auto &n:nums){
            freq[n]++;
            maxi=max(maxi,freq[n]);
        }
        for(auto &f:freq){
            if(maxi==f)cnt++;
            ans=maxi*cnt;
        }

        return ans;
    }
};