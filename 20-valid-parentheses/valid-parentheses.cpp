class Solution {
public:
    bool check(char ch1,char ch2){
        if((ch1==')' && ch2=='(')||(ch1=='}' && ch2=='{')||(ch1==']' && ch2=='['))return true;
        return false;
    }
    bool isValid(string s) {
        string st="";
        for(char &ch:s){
            if(ch=='('||ch=='{'||ch=='[')st.push_back(ch);
            else if(ch==')'||ch=='}'||ch==']'){
                if(st.empty())return false;
                char top = st.back();
                if(!check(ch,top))return false;
                st.pop_back();
            }
        }
        return st.empty();
    }
};
// Time Complexity O(n)
// Space Complexity O(n)