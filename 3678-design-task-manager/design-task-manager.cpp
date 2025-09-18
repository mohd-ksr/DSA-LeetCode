
struct taskMan {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        if (a[2] != b[2]) return a[2] < b[2];  
        return a[1] < b[1];                    
    }
};

class TaskManager {
private:
    priority_queue<vector<int>, vector<vector<int>>, taskMan> tsks;
    unordered_map<int, pair<int,int>> cur; 

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &v : tasks) {
            tsks.push(v);
            cur[v[1]] = {v[0], v[2]};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        tsks.push({userId, taskId, priority});
        cur[taskId] = {userId, priority};
    }
    
    void edit(int taskId, int newPriority) {
        if (cur.find(taskId) == cur.end()) return; 
        int userId = cur[taskId].first;
        cur[taskId] = {userId, newPriority};
        tsks.push({userId, taskId, newPriority}); 
    }
    
    void rmv(int taskId) {
        cur.erase(taskId); 
    }
    
    int execTop() {
        while (!tsks.empty()) {
            auto entry = tsks.top();
            int userId = entry[0], taskId = entry[1], priority = entry[2];
            tsks.pop();

            if (cur.find(taskId) != cur.end() && cur[taskId] == make_pair(userId, priority)) {
                cur.erase(taskId); 
                return userId;     
            }
        }
        return -1; 
    }
};


/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */