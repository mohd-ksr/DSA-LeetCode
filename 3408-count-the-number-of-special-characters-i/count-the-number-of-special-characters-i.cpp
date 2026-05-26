class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool small[26];
        bool cap[26];
        for(int i=0; i<26; i++){
            small[i]=false;
            cap[i]=false;
        }
        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(ch>='a' && ch<='z'){
                int ind = ch-'a';
                small[ind]=true;
            }
            else{
                int ind = ch-'A';
                cap[ind]=true;
            }
        }
        int ans=0;
        for(int i=0; i<26; i++){
            if(small[i]==true && cap[i]==true){
                ans++;
            }
        }

        return ans;
    }
};