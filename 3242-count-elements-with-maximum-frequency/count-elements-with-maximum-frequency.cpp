class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto n: nums){
            freq[n]++;
        }
        int maxi = 0;
        for(auto it: freq){
            maxi = max(maxi, it.second);
        }

        int count = 0;
        for(auto it: freq){
            if(it.second==maxi){
                count++;
            }
        }

        return count*maxi;

        
    }
};