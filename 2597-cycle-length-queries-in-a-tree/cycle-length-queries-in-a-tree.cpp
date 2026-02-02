class Solution {
private:
    int solve(int x, int y){
        int c = 0;
        while(x!=y){
            if(x>y)x>>=1;
            else y>>=1;
            c++;
        }
        return c+1;
    }
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto q:queries){
            ans.push_back(solve(q[0],q[1]));
        }
        return ans;
    }
};