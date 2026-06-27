class Solution {
private:
    void rev(string &s, int l, int h){
        while(l<h){
            swap(s[l],s[h]);
            l++;
            h--;
        }
    }
public:
    string reverseParentheses(string s) {
        stack<int>st;
        queue<pair<int, int>>q;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(')st.push(i);
            else if(s[i]==')'){
                q.push({st.top(), i});
                st.pop();
            }
        }

        while(!q.empty()){
            rev(s, q.front().first+1, q.front().second-1);
            q.pop();
        }
        string ans="";
        for(auto ch:s){
            if(ch=='(' || ch==')')continue;
            ans+=ch;
        }
        return ans;
    }
};