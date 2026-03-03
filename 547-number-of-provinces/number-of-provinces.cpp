class DSU{
public:
    vector<int>p,r;

    DSU(int n){
        p.resize(n+1);
        r.resize(n+1, 0);
        for(int i=0; i<=n; i++)p[i]=i;
    }

    int fup(int node){
        if(p[node]==node)return node;
        return p[node] = fup(p[node]);
    }

    void ubr(int u, int v){
        int pu = fup(u);
        int pv = fup(v);
        if(pu==pv)return;
        if(r[pu] < r[pv]){
            p[pu] = pv;
        }
        else if(r[pu] > r[pv]){
            p[pv] = pu;
        }
        else{
            p[pv] = pu;
            r[pu]++;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU ds(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(isConnected[i][j]==1){
                    ds.ubr(i, j);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            if(ds.p[i]==i)ans++;
        }
        return ans;
    }
};