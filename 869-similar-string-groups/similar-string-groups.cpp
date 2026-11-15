class DSU{
private:
    vector<int>parent,rank,size;
public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
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

        if(ulp_u == ulp_v)return ;

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
    void unionBySize(int u, int v){
        int ulp_u = findUlp(u);
        int ulp_v = findUlp(v);
        if(ulp_u == ulp_v)return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    int getSize(int node){
        return size[findUlp(node)];
    }
};
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DSU ds(n);
        for(int i=0; i<n; i++){
            string a = strs[i];
            for(int j=i+1; j<n; j++){
                string b = strs[j];
                int count = 0;
                for(int k=0; k<a.size(); k++){
                    if(a[k]!=b[k])count++;
                    if(count>2)break;
                }
                if(count<=2)ds.unionByRank(i, j);
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            if(ds.findUlp(i)==i)ans++;
        }
        return ans;
    }
};