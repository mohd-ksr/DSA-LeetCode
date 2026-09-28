class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int b=0;
        for(char ch:s){
            if(ch=='(')b++;
            if(ch==')'){
                ans=max(ans,b);
                b--;
            }
        }
        return ans;
    }
};