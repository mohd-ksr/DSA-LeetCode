class Solution {
public:
    string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0"; 
    vector<string> inter;
    for (int i = num1.size() - 1; i >= 0; i--) {
        string temp = "";
        for (int k = num1.size() - 1; k > i; k--) temp.push_back('0');
        int carry = 0; 
        for (int j = num2.size() - 1; j >= 0; j--) {
            int n = (num1[i] - '0') * (num2[j] - '0') + carry;
            temp.push_back('0' + (n % 10));
            carry = n / 10;
        }
        if (carry) temp.push_back('0' + carry);
        reverse(temp.begin(), temp.end());
        inter.push_back(temp);
    }

    string ans = "";
    int i = 0;
    int maxi = 0;
    for (auto &s : inter) maxi = max(maxi, (int)s.length());
    int carr = 0;
    while (i < maxi || carr) {
        int t = carr;
        for (auto &s : inter) {
            if ((int)s.size() - i - 1 >= 0) {
                t += (s[s.size() - i - 1] - '0');
            }
        }
        ans.push_back('0' + (t % 10));
        carr = t / 10;
        i++;
    }
    reverse(ans.begin(), ans.end());

    int pos = ans.find_first_not_of('0');
    if (pos != string::npos) return ans.substr(pos);
    return "0";
}
};