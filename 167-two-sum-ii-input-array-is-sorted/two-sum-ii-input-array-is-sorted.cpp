class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s = 0, e = numbers.size()-1;
        while(s<=e){
            int val = numbers[s]+numbers[e];
            if(val==target)return {s+1,e+1};
            else if(val>target)e--;
            else s++;
        }
        return {}; //dummy
    }
};
// Time complexity O(n)