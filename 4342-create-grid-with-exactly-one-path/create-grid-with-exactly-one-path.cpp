class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string r = "";
        vector<string>ans;
        r.append(n, '.');
        ans.push_back(r);
        for(int i=1; i<m; i++){
            r="";
            r.append(n, '#');
            r[n-1]='.';
            ans.push_back(r);
        }
        return ans;
    }
};