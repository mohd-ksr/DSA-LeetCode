class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        string temp="";
        int count = 0;
        for(auto &ch:s){
            if(ch=='(')count++;
            else count--;
            temp.push_back(ch);
            if(count==0){
                ans+=temp.substr(1,temp.size()-2);
                temp="";
            }
        }
        return ans;
    }
};