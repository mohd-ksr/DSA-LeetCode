class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto flight:flights){
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            adj[from].push_back({to, price});
        }
        queue<pair<int, pair<int, int>>>q; // {stops, city, price};
        vector<int>TotalCost(n, 1e9);
        q.push({0, {src, 0}});
        TotalCost[src]=0;
        while(!q.empty()){
            int stops = q.front().first;
            auto [city, priceTillNow] = q.front().second;
            q.pop();
            if(stops>k)continue;
            for(auto [neiCity, price] : adj[city]){
                if(priceTillNow + price < TotalCost[neiCity]){
                    TotalCost[neiCity] = price+priceTillNow;
                    q.push({stops+1, {neiCity, TotalCost[neiCity]}});
                }
            }
        }
        return TotalCost[dst]==1e9 ? -1 : TotalCost[dst];
    }
};