class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>s1;
        int ans=0;
        for(char ch:s)s1.insert(ch);
        for(auto ch:s1){
            int i=-1;
            int j = 0;
            for(int k=0; k<s.size(); k++){
                if(s[k]==ch){
                    if(i==-1)i=k;
                    j=k;
                }
            }
            unordered_set<char>s2;
            for(int k=i+1; k<j; k++){
                s2.insert(s[k]);
            }
            ans+=s2.size();
        }
        return ans;
    }
};