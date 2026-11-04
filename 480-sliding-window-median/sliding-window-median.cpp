class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double>ans;
        int i=0, j=0;
        multiset<int>left, right;
        while(j<n){
            // inserting
            if(left.size() <= right.size()){
                left.insert(nums[j]);
            }
            else{
                right.insert(nums[j]);
            }

            // balancing
            int leftSize = left.size();
            int rightSize = right.size();
            while(leftSize > 0 && rightSize > 0){
                int leftMax = *left.rbegin();
                int rightMin = *right.begin();
                if(leftMax > rightMin){
                    left.insert(rightMin);
                    right.insert(leftMax);
                    left.erase(left.find(leftMax));
                    right.erase(right.find(rightMin));
                }
                else break;
            }

            if(j-i+1 == k){
                if(k&1){
                    ans.push_back(*left.rbegin());
                }
                else{
                    double l = *left.rbegin();
                    double r = *right.begin();
                    ans.push_back((l+r)/2);
                }
                if(left.find(nums[i])!=left.end()){
                    left.erase(left.find(nums[i]));
                }
                else{
                    right.erase(right.find(nums[i]));
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};