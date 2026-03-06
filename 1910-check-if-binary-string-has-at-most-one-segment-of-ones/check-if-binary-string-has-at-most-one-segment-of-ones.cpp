class Solution {
public:
    bool checkOnesSegment(string s) {
        bool tog = false;
        for(int i=1; i<s.size(); i++){
            if(s[i]=='1' && tog)return false;
            else if(s[i]=='0')tog=true;
        }
        return true;
    }
};