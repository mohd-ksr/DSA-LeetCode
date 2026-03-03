class Solution {
private:
    string inv(string s){
        for(auto &ch:s){
            if(ch=='1')ch='0';
            else ch='1';
        }
        return s;
    }
    string rev(string s){
        reverse(s.begin(), s.end());
        return s;
    }
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i=2; i<=n; i++){
            cout<<s<<"\n";
            string temp = s + "1" + rev(inv(s));
            s=temp;
        }
        return s[k-1];
    }
};