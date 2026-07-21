class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<pair<int, int>>vec;
        int oneCount = 0;
        int st=-1;
        for(int e=0; e<n; e++){
            if(s[e]=='1'){
                if(st!=-1){
                    vec.push_back({st, e-1});
                    st=-1;
                }
                oneCount++;
            }
            else{
                if(st==-1){
                    st=e;
                }
                if(e==n-1){
                    vec.push_back({st, e});
                }
            }
        }
        // for(auto it:vec){
        //     cout<<it.first<<" "<<it.second<<"\n";
        // }
        int maxi = 0;
        for(int i=1; i<vec.size(); i++){
            maxi = max(maxi, (vec[i].second-vec[i].first+1 + vec[i-1].second-vec[i-1].first+1));
        }
        return maxi+oneCount;
    }
};