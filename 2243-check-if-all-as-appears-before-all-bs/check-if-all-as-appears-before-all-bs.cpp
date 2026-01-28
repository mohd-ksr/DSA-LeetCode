class Solution {
public:
    bool checkString(string s) {
        bool bStart = false;
        for(auto &ch:s){
            if(bStart && ch=='a')return false;
            if(ch=='b')bStart = true;
        }
        return true;
    }
};