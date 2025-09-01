class Solution {
private:
    double gain(int pass, int total){
        return (double)(pass+1)/(total+1) - (double)pass/total;
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<array<double,3>>pq;
        for(auto &c:classes){
            int pass=c[0], total=c[1];
            pq.push({gain(pass,total),(double)pass,(double)total});
        }
        while(extraStudents--){
            auto top = pq.top();pq.pop();
            int pass=top[1],total=top[2];
            pass++;total++;
            pq.push({gain(pass,total), (double)pass, (double)total});
        }
        double sum=0.0;
        while(!pq.empty()){
            auto top=pq.top(); pq.pop();
            sum+=top[1]/top[2];
        }
        return sum/classes.size();
    }
};
// Time complexity O((n + extraStudents) log n)
// space complexity O(n)
