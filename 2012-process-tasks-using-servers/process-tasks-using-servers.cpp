class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> freeServers;
        using P = pair<long long, pair<int,int>>;
        priority_queue<P, vector<P>, greater<P>> busyServers;
        int n = servers.size();
        int m = tasks.size();
        for(int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }
        vector<int> ans(m);
        long long currentTime = 0;

        for(int i = 0; i < m; i++) {
            currentTime = max(currentTime, (long long)i);
            while(!busyServers.empty() && busyServers.top().first <= currentTime) {
                auto [endTime, info] = busyServers.top();
                busyServers.pop();
                freeServers.push(info);
            }
            if(freeServers.empty()) {
                currentTime = busyServers.top().first;
                while(!busyServers.empty() && busyServers.top().first <= currentTime) {

                    auto [endTime, info] = busyServers.top();
                    busyServers.pop();

                    freeServers.push(info);
                }
            }
            auto [weight, index] = freeServers.top();
            freeServers.pop();

            ans[i] = index;
            busyServers.push({currentTime + tasks[i],{weight, index}});
        }
        return ans;
    }
};