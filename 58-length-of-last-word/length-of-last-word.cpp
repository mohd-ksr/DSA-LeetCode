class Solution {
public:
    int lengthOfLastWord(string s) {
        int ind = s.size()-1;
        while(ind>=0 && s[ind]==' ')ind--;
        int count = 0;
        while(ind>=0 && s[ind]!=' '){
            ind--;
            count++;
        }
        return count;
    }
};