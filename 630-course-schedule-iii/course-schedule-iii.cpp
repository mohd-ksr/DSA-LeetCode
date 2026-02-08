class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int totalTime = 0, count = 0;
        sort(courses.begin(), courses.end(), [](vector<int>&a, vector<int>&b){
            return a[1]<b[1];
        });

        for(auto c:courses){
            cout<<c[0]<<" "<<c[1]<<endl;
        }
        priority_queue<pair<int, int>>pq;
        for(int i=0; i<courses.size(); i++){
            int d = courses[i][0];
            int ld = courses[i][1];
            pq.push({d, ld});
            totalTime+=d;
            if(!(totalTime<=ld)){
                totalTime-=pq.top().first;
                pq.pop();
            }
        }

        return pq.size();
    }
};

