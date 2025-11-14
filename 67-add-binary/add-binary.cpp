class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int n=max(a.length(),b.length());
        char carry='0';

        for(int i=0; i<n; i++){
            char ba='0';
            char bb='0';

            if(i<a.length()) ba =a[a.length()-i-1];
            if(i<b.length()) bb =b[b.length()-i-1];

            if (ba == '0' && bb == '0' && carry == '0') {
            ans = '0' + ans;
            carry = '0';
            } else if (ba == '0' && bb == '0' && carry == '1') {
            ans = '1' + ans;
            carry = '0';
            } else if (ba == '0' && bb == '1' && carry == '0') {
            ans = '1' + ans;
            carry = '0';
            } else if (ba == '0' && bb == '1' && carry == '1') {
            ans = '0' + ans;
            carry = '1';
            } else if (ba == '1' && bb == '0' && carry == '0') {
            ans = '1' + ans;
            carry = '0';
            } else if (ba == '1' && bb == '0' && carry == '1') {
            ans = '0' + ans;
            carry = '1';
            } else if (ba == '1' && bb == '1' && carry == '0') {
            ans = '0' + ans;
            carry = '1';
            } else if (ba == '1' && bb == '1' && carry == '1') {
            ans = '1' + ans;
            carry = '1';
            }
        }
        if(carry=='1') ans='1'+ans;
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)