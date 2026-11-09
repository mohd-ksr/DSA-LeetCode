class DSU{
private:
    vector<int>parent,rank;
public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }
    int findUlp(int node){
        if(parent[node]==node)return node;
        return parent[node] = findUlp(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulp_u = findUlp(u);
        int ulp_v = findUlp(v);
        if(ulp_u == ulp_v)return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU ds(n);
        unordered_map<string, int>emailInd;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string email = accounts[i][j];
                if(emailInd.find(email)==emailInd.end()){
                    emailInd[email] = i;
                }
                else{
                    ds.unionByRank(i, emailInd[email]);
                }
            }
        }
        unordered_map<int, vector<string>>indexedMapedEmails;
        for(auto it:emailInd){
            string email = it.first;
            int ind = it.second;
            int actualInd = ds.findUlp(ind);
            indexedMapedEmails[actualInd].push_back(email);
        }
        vector<vector<string>>ans;
        for(auto it:indexedMapedEmails){
            int ind = it.first;
            vector<string> mergedEmails = it.second;
            sort(mergedEmails.rbegin(), mergedEmails.rend());
            string name = accounts[ind][0];
            mergedEmails.push_back(name);
            reverse(mergedEmails.begin(), mergedEmails.end());
            ans.push_back(mergedEmails);
        }
        return ans;
    }
};











