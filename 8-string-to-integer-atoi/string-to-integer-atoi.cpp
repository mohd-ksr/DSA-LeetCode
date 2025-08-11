class Solution {
public:
    int myAtoi(string s) {
        int i=0, n=s.length();
        while(i<n && s[i]==' ')i++;
        int sign=1;
        long result=0;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            sign=(s[i]=='-'?-1:1);
            i++;
        }
        while(i<n && isdigit(s[i])){
            result=result*10+(s[i]-'0');
            if(sign==1 && result>INT_MAX)return INT_MAX;
            if(sign==-1 && -result<INT_MIN)return INT_MIN;

            i++;
        }
        return static_cast<int>(result*sign);
    }
};
// Time complexity O(n);
// space complexity O(1);