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
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        for(int i=0; i<n; i++){
            row[i] = row[i]/2;
        }
        DSU ds(n/2);
        for(int i=0; i<n; i+=2){
            for(int j=i+2; j<n; j+=2){
                if(row[i]==row[j] || row[i]==row[j+1] || row[i+1]==row[j] || row[i+1]==row[j+1]){
                    ds.unionBySize(i/2, j/2);
                }
            }
        }
        int ans = 0;
        set<int>st;
        for(int i=0; i<n/2; i++){
            if(!st.count(ds.findUlp(i))){
                ans += ds.getSize(i) - 1;
                st.insert(ds.findUlp(i));
            }
        }
        return ans;
    }
};