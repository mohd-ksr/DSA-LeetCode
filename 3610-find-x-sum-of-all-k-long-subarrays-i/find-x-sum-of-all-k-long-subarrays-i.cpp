class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i <= n - k; i++) {
            // Get the current window
            vector<int> window(nums.begin() + i, nums.begin() + i + k);
            
            // Count frequencies
            unordered_map<int, int> freq;
            for (int num : window) {
                freq[num]++;
            }
            
            // Convert to vector for sorting
            vector<pair<int, int>> freqList(freq.begin(), freq.end());
            
            // Sort by (-frequency, -value)
            sort(freqList.begin(), freqList.end(), [](auto &a, auto &b) {
                if (a.second == b.second)
                    return a.first > b.first;  // Larger number first if tie
                return a.second > b.second;     // Higher frequency first
            });
            
            // Pick top x elements
            unordered_set<int> topX;
            for (int j = 0; j < x && j < freqList.size(); j++) {
                topX.insert(freqList[j].first);
            }
            
            // Calculate sum of occurrences
            int total = 0;
            for (int num : window) {
                if (topX.count(num)) total += num;
            }
            
            result.push_back(total);
        }
        
        return result;
    }
};
