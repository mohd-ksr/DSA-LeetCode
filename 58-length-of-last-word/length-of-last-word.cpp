class Solution {
public:
    int lengthOfLastWord(string s) {
        string temp="";
        for(int i=s.length()-1;i>=0; i--){
            if(s[i]==' '){
                if(temp.length()) break;
                else continue;
            }
            temp+=s[i];
        }
        return temp.length();
    }
};
// Time complexity O(n)
// Space complexity O(n)