class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(j==i)continue;
                 if (!(points[i][0] <= points[j][0] && points[i][1] >= points[j][1])) continue; 
                bool flag=true;
                for(int k=0; k<n; k++){
                    if(k==i || k==j)continue;
                    int x1=points[i][0], x2=points[j][0], x=points[k][0];
                    int y1=points[i][1], y2=points[j][1], y=points[k][1];
                    if(x1 <= x && x <= x2 && y2 <= y && y <= y1)flag=false;
                }
                if(flag)count++;
            }
        }
        return count;
    }
};