class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long, long long>mapp;
        int n = tasks.size();
        long long time = 0L;
        for(int i=0; i<n; i++){
            time++;
            if(mapp.find(tasks[i])!=mapp.end()){
                if(time < mapp[tasks[i]])time = mapp[tasks[i]];
            }
            mapp[tasks[i]] = time + space + 1;
        }
        return time;
    }
};