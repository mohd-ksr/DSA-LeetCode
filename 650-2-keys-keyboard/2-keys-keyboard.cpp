class Solution {
private: 
    int solve(int n, int curLen, int pasteLen){
        if(curLen==n)return 0;
        if(curLen>n)return 1000;

        int opt1 = 2+solve(n, curLen*2, curLen);
        int opt2 = 1 + solve(n, curLen+pasteLen, pasteLen);

        return min(opt1, opt2);
    }
public:
    int minSteps(int n) {
        if(n==1)return 0;
        return 1+solve(n,1,1);
    }
};