class Solution {
public:
    int reverseBits(int n) {
        string str = "";
        while(n){
            str.push_back('0'+(n&1));
            n>>=1;
        }
        while(str.length()<32){
            str.push_back('0');
        }
        reverse(str.begin(), str.end());
        int ans = 0;
        for(int i=0; i<32; i++){
            if(str[i]=='1')ans+=pow(2,i);
        }
        cout<<str.length()<<" ";
        cout<<str;
        return ans;
    }
};