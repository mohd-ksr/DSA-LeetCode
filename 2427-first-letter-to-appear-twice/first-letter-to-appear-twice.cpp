class Solution {
public:
    char repeatedCharacter(string s) {
        vector<char>alpha(26, '0');
        for(auto ch:s){
            if(alpha[ch-'a']=='1')return ch;
            alpha[ch-'a']='1';
        }
        return 'a';
    }
};