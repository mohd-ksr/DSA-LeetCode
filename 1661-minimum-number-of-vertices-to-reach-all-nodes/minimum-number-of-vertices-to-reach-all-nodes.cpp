class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>cand(n, true);
        for(auto &e:edges){
            cand[e[1]]=false;
        }

        vector<int>ans;
        for(int i=0; i<n; i++){
            if(cand[i])ans.push_back(i);
        }

        return ans;
    }
};