class DSU{
private:
    vector<int>parent, rank;
public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0; i<=n;i++)parent[i]=i;
    }

    int findUpar(int node){
        if(parent[node]==node)return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
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
        unordered_map<string, int>mapp;

        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string email = accounts[i][j];
                if(mapp.find(email)==mapp.end()){
                    mapp[email] = i;
                }
                else{
                    ds.unionByRank(i, mapp[email]);
                }
            }
        }
        unordered_map<int, vector<string>>mapp2;
        for(auto it:mapp){
            string email = it.first;
            int node = ds.findUpar(it.second);
            mapp2[node].push_back(email);
        }

        vector<vector<string>>ans;

        for(auto it:mapp2){
            vector<string>temp;
            int node = it.first;
            temp.push_back(accounts[node][0]);
            vector<string>t = it.second;
            sort(t.begin(), t.end());
            for(auto e:t){
                temp.push_back(e);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};