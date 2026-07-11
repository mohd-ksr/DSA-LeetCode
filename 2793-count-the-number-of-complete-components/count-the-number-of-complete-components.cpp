class DSU{
public:
    vector<int>rank,parent;
    DSU(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }
    int findUlp(int node){
        if(node==parent[node])return node;
        return parent[node]=findUlp(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUlp(u);
        int ulp_v = findUlp(v);

        if(ulp_u==ulp_v)return;

        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>dig(n, 0);
        DSU ds(n);
        for(auto e:edges){
            dig[e[0]]++;
            dig[e[1]]++;
            ds.unionByRank(e[0], e[1]);
        }
        unordered_map<int, vector<int>>mapp;
        for(int i=0; i<n; i++){
            // cout<<ds.findUlp(i)<<" ";
            mapp[ds.findUlp(i)].push_back(i);
        }
        // cout<<endl;
        // for(int i=0; i<n; i++){
        //     cout<<dig[i]<<" ";
        // }

        int ans = 0;
        for(auto it:mapp){
            vector<int>vec = it.second;
            int non = vec.size();
            bool flag = true;
            for(int i=0; i<non; i++){
                if(dig[vec[i]] < non-1){
                    flag=false;
                    break;
                }
            }
            ans+=flag;
        }
        return ans;
    }
};