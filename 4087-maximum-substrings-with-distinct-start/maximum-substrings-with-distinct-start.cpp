class Solution {
public:
    int maxDistinct(string s) {
    //    vector<int>t(26,0);
    //     int ans = 0;
    //     for(char ch:s){
    //         if(!t[ch-'a']){
    //             t[ch-'a']=1;
    //             ans++;
    //         }
    //     }
    //     return ans;
        unordered_set<char>st;
        for(char &ch:s)st.insert(ch);
        return st.size();
    }
};