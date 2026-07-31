class Solution {
private:
    vector<string>mapp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string>ans;
    void solve(int ind, string &digits, string temp){
        if(ind>=digits.size()){
            ans.push_back(temp);
            return;
        }

        int d = digits[ind]-'0';
        for(auto ch:mapp[d]){
            temp.push_back(ch);
            solve(ind+1, digits, temp);
            temp.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        solve(0, digits, "");
        return ans;
    }
};