class Solution {
public:
    int minAddToMakeValid(string s) {
        int oc = 0;
        int cc = 0;
        for(auto &ch:s){
            if(ch=='(')oc++;
            else oc--;
            if(oc<0){
                oc++;
                cc++;
            }
        }
        return oc+cc;
    }
};