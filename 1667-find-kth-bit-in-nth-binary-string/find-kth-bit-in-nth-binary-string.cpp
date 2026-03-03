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
        if(n==1)return '0';
        int len = (1<<n)-1;

        int mid = len/2 + 1;

        if(mid==k)return '1';

        else if(k<mid) return findKthBit(n-1, k);

        return findKthBit(n-1, len-k+1) == '0'? '1':'0';
    }
};