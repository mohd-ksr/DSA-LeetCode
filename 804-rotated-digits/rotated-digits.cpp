class Solution {
private:
    bool isValid(int n){
        bool v = false;
        while(n){
            int d = n%10;
            if(d==3 || d==4 || d==7)return false;
            if(d==2 || d==5 || d==6 || d==9)v=true;
            n/=10;
        }
        return v;
    }
public:
    int rotatedDigits(int n) {
        int count = 0;
        for(int i=1; i<=n; i++){
            if(isValid(i))count++;
        }
        return count;
    }
};