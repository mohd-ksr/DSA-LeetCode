class Solution {
public:
    bool rotateString(string s, string goal) {
        return(s.size()==goal.size() && (s+s).contains(goal));
    }
};