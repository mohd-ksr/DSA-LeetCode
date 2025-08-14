class Solution {
private:
    string maxStr(string a, string b){
        return a>b?a:b;
    }
public:
    string largestGoodInteger(string num) {
        string ans="";
        string str="";
        for(auto &curr:num){
            if(str.empty() || str.back()==curr){
                str.push_back(curr);
            }
            else{
                str="";
                str.push_back(curr);
            }
            if(str.size()==3){
                ans=maxStr(ans,str);
            }
        }
        return ans;
    }
};
// Time Complexity O(n)
// Space Complexity O(1)