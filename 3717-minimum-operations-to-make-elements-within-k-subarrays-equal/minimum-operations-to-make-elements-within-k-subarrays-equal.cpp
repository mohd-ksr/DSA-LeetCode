class Solution {
private:
    vector<long long>costs;
    int n, x, k;
    long long inf = 1e15;
    vector<vector<long long>>dp;
    void fillCosts(vector<int>&nums){
        multiset<int> left, right;
        int i = 0, j = 0;
        long long leftSum = 0L, rightSum = 0L;
        while(j<n){
            //Insert element according to size of left right
            if(left.size() <= right.size()){
                left.insert(nums[j]);
                leftSum += nums[j];
            }
            else{
                right.insert(nums[j]);
                rightSum += nums[j];
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
                    leftSum -= leftMax;
                    leftSum += rightMin;
                    rightSum -= rightMin;
                    rightSum += leftMax;
                }
                else break;
            }
            if(j-i+1 == x){
                int median = *left.rbegin();
                long long leftCost = left.size()*median - leftSum;
                long long rightCost = rightSum - right.size()*median;
                costs[i] = leftCost + rightCost;
                if(left.find(nums[i]) != left.end()){
                    left.erase(left.find(nums[i]));
                    leftSum -= nums[i];
                }
                else{
                    right.erase(right.find(nums[i]));
                    rightSum -= nums[i];
                }
                i++;
            }
            j++;
        }
    }
    long long solve(int ind, int count){
        if(count==k)return 0;
        if(ind+((k-count)*x)-1 >= n) return inf;
        if(dp[ind][count]!=-1)return dp[ind][count];
        return dp[ind][count] = min(costs[ind]+solve(ind+x, count+1), solve(ind+1, count));
    }
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        n = nums.size();
        this->x = x;
        this->k = k;
        costs.resize(n, 0L);
        fillCosts(nums);
        dp.resize(n, vector<long long>(k, -1));
        return solve(0, 0);
    }
};