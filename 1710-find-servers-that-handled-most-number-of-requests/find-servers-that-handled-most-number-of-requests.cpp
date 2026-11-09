class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int>count(k, 0);
        set<int>st;
        for(int i=0; i<k; i++)st.insert(i);
        for(int i=0; i<n; i++){
            int currentTime = arrival[i];
            while(!pq.empty() && pq.top().first <= currentTime){
                st.insert(pq.top().second);
                pq.pop();
            }
            int endTime = currentTime + load[i];
            if(st.empty())continue;
            int serverId = (i+k)%k;
            auto it = st.lower_bound(serverId);
            if(it == st.end()){
                it = st.begin();
            }
            serverId = *it;
            st.erase(serverId);
            count[serverId]++;
            pq.push({endTime, serverId});
        }
        int maxi = *max_element(count.begin(), count.end());
        vector<int>ans;
        for(int i=0; i<k; i++){
            if(count[i]==maxi)ans.push_back(i);
        }
        return ans;
    }
};