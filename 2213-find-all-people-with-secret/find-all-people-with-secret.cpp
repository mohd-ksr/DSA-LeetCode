class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int fp) {

        map<int, vector<pair<int,int>>> timeMeetings;
        for (auto &m : meet) {
            int x = m[0], y = m[1], t = m[2];
            timeMeetings[t].push_back({x, y});
        }

        vector<bool> ks(n, false);
        ks[0] = true;
        ks[fp] = true;

        for (auto &entry : timeMeetings) {
            int t = entry.first;
            auto &meetings = entry.second;

            unordered_map<int, vector<int>> meetList;
            for (auto &p : meetings) {
                int x = p.first, y = p.second;
                meetList[x].push_back(y);
                meetList[y].push_back(x);
            }
            unordered_set<int> start;
            for (auto &p : meetings) {
                int x = p.first, y = p.second;
                if (ks[x]) start.insert(x);
                if (ks[y]) start.insert(y);
            }

            queue<int> q;
            for (int s : start) q.push(s);

            while (!q.empty()) {
                int person = q.front();
                q.pop();

                for (int nextPerson : meetList[person]) {
                    if (!ks[nextPerson]) {
                        ks[nextPerson] = true;
                        q.push(nextPerson);
                    }
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (ks[i]) res.push_back(i);
        }
        return res;
    }
};