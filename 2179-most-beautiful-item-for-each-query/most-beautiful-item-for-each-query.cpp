class Solution {
private:
    int bs(vector<vector<int>>& items, int t){
        int s=0, e=items.size()-1;
        int maxi=0;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(items[mid][0]>t)e=mid-1;
            else{
                maxi = max(maxi,items[mid][1]);
                s=mid+1;
            }
        }
        return maxi;
    }
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // vector<int> ans;
        // for(int q:queries){
        //     int maxi = 0;
        //     for(auto p:items){
        //         if(p[0]<=q)maxi = max(maxi,p[1]);
        //     }
        //     ans.push_back(maxi);
        // }
        // return ans;

        sort(items.begin(),items.end(), [](vector<int>&a, vector<int>&b){return a[0]<b[0];});
        vector<int>ans(queries.size());
        int maxi = items[0][1];
        for(int i=0; i<items.size(); i++){
            maxi = max(maxi,items[i][1]);
            items[i][1]=maxi;
        }
        for(int i=0; i<queries.size(); i++){
            ans[i]=bs(items,queries[i]);
        }
        return ans;
    }
};
