class Solution {
private:
    int sod(int n){
        return n==0?0:n%10+sod(n/10);
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<tuple<int, int, int>>indArr;
        for(int i=0; i<n; i++){
            indArr.push_back({sod(nums[i]), nums[i], i});
        }
        sort(indArr.begin(), indArr.end());
        int swaps = 0;
        vector<int>vis(n, 0);
        for(int i=0; i<n; i++){
            if(vis[i] || get<2>(indArr[i])==i)continue;
            int c = 0;
            int j=i;
            while(!vis[j]){
                vis[j]=1;
                j=get<2>(indArr[j]);
                c++;
            }
            swaps+=c-1;
        }
        return swaps;
    }
};