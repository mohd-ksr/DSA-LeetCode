class Solution {
private:
    void generate(int &n, vector<string>&ans, string temp, int o, int c){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }
        if(o<n)generate(n,ans,temp+'(',o+1,c);
        if(o>c)generate(n,ans,temp+')',o,c+1);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int o=0,c=0;
        generate(n,ans,"",o,c);
        return ans;
    }
};
// Time Complexity O(4^n / √n)
// Space Complexity O(n)