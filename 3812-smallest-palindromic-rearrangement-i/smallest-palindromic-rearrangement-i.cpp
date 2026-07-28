class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26, 0);
        for(auto ch:s){
            int ind = ch - 'a';
            freq[ind]++;
        }
        char ch = ('a' - 1);
        string ans = "";
        for(int i=0; i<26; i++){
            int cnt = freq[i];
            if(cnt&1)ch = ('a'+i);
            cnt/=2;
            while(cnt--){
                ans.push_back(('a'+i));
            }
        }
        string temp = ans;
        if(ch>='a')ans.push_back(ch);
        reverse(temp.begin(), temp.end());
        ans+=temp;
        return ans;
    }
};