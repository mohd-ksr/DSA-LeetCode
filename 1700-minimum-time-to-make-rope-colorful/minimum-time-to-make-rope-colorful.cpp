class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;
        int i=1;
        while(i<n){
            int minInd =i-1;
            bool flag = false;
            while(i<n && colors[i]==colors[i-1]){
                flag = true;
                if(neededTime[i]<neededTime[minInd]){
                    ans+=neededTime[i];
                }else{
                    ans+=neededTime[minInd];
                    minInd=i;
                }
                i++;
            }
            if(!flag)i++;
        }
        return ans;
    }
};