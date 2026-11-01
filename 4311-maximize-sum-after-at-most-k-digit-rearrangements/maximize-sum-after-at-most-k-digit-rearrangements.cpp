class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        vector<pair<int, int>>vec;
        for(int num:nums){
            string s = to_string(num);
            sort(s.rbegin(), s.rend());
            vec.push_back({stoi(s)-num, num});
        }
        sort(vec.rbegin(), vec.rend());
        long long sum = 0;
        int ind = 0;
        while(k--){
            if(vec[ind].first > 0){
                sum += vec[ind].first + vec[ind].second;
                ind++;
            }
            else break;
        }
        for(;ind<nums.size(); ind++){
            sum+=vec[ind].second;
        }
        return sum;
    }
};