class Solution {
private:
    vector<string>ans;
    int n;
    void solve(int oc, int cc, string temp){
        if(oc+cc == 2*n){
            ans.push_back(temp);
        }
        if(oc<n)solve(oc+1, cc, temp+'(');
        if(cc<oc)solve(oc, cc+1, temp+')');
    }
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        solve(0,0,"");
        return ans;
    }
};