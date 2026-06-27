class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<char> st;
        for(auto ch:s){
            if(ch==')'){
                while(true){
                    if(st.top()=='('){
                        st.pop();
                        break;
                    }
                    ans+=st.top();
                    st.pop();
                }
                for(auto ch1:ans){
                    st.push(ch1);
                }
                ans="";
            }
            else{
                st.push(ch);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};