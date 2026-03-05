class Solution {
public:
    int minOperations(string s) {
        string t1="", t2="";
        int n = s.size();
        for(int i=0; i<n; i++){
            if(i&1){
                t1.push_back('0');
                t2.push_back('1');
            }
            else{
                t1.push_back('1');
                t2.push_back('0');
            }
        }
        int mini1=0, mini2=0;
        for(int i=0; i<n; i++){
            if(s[i]!=t1[i])mini1++;
            if(s[i]!=t2[i])mini2++;
        }

        return min(mini1, mini2);
    }
};