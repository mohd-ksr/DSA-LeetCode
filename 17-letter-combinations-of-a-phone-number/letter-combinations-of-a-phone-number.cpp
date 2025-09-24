class Solution {
private:
    vector<string>result;
    void solve(int i, string &digits, string &temp, unordered_map<char,string>&mapp){
        if(i>=digits.length()){
            result.push_back(temp);
            return;
        }

        char ch=digits[i];
        string str=mapp[ch];

        for(int j=0; j<str.length(); j++){
            temp.push_back(str[j]);
            solve(i+1,digits,temp,mapp);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()<=0)return {};
        unordered_map<char,string>mapp;
        mapp['2']="abc";
        mapp['3']="def";
        mapp['4']="ghi";
        mapp['5']="jkl";
        mapp['6']="mno";
        mapp['7']="pqrs";
        mapp['8']="tuv";
        mapp['9']="wxyz";
        string temp="";
        solve(0,digits,temp,mapp);
        return result;
    }
};
// Time Complexity O(4^n)
// Space Complexity O(n)