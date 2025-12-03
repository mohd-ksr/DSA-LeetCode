class Solution {
public:
    bool isPerfectSquare(int num) {
        int s = sqrt(num);
        return s*s==num;
    }
};