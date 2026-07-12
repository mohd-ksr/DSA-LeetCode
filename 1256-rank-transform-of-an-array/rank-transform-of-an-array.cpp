class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n==0)return {};
        
        vector<pair<int, int>>vec(n);
        for(int i=0; i<arr.size(); i++){
            vec[i] = {arr[i], i};
        }
        sort(vec.begin(), vec.end());
        vector<int>ans(n);
        ans[vec[0].second] = 1;
        for(int i=1; i<n; i++){
            if(vec[i-1].first == vec[i].first){
                ans[vec[i].second] = ans[vec[i-1].second];
            }
            else{
                ans[vec[i].second] = ans[vec[i-1].second]+1;
            }
        }
        return ans;
    }
};