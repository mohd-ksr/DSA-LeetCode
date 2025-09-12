class Solution {
public:
    bool doesAliceWin(string s) {
        for(auto &ch:s){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')return true;
        }
        return false;
    }
};
// Time Comlexity O(n)
// Space Complexity O(1)