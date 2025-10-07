class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
    int n = rains.size();
    vector<int> ans(n, 1); 
    unordered_map<int, int> full; 
    set<int> dryDays; 
    
    for(int i = 0; i < n; i++){
        if (rains[i] > 0) {
            int lake = rains[i];
            ans[i] = -1; 
            
            if(full.count(lake)){
                int last = full[lake];
                
                auto it = dryDays.lower_bound(last);
                if (it == dryDays.end()) {
                    return {}; 
                }
                
                ans[*it] = lake;
                dryDays.erase(it);
            }
            full[lake] = i;
        } 
        else {
            dryDays.insert(i); 
        }
    }
    return ans;
}
};