class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>small(26,-1);
        vector<int>cap(26,-1);
        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(ch>='a' && ch<='z'){
                int ind = ch-'a';
                small[ind]=i;
            }
            else{
                int ind = ch-'A';
                if(cap[ind]==-1){
                    cap[ind]=i;
                }
            }
        }
        int ans=0;
        for(int i=0; i<26; i++){
            if(small[i]==-1 || cap[i]==-1)continue;
            if(small[i]<cap[i])ans++;
        }
        return ans;
    }
};