class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            unordered_map<char,int>mapp;
            for(int j=i; j<n; j++){
                mapp[s[j]]++;

                bool ok = true;
                for(auto &it:mapp){
                    if(it.second<k){
                        ok=false;
                        break;
                    }
                }
                if(ok)ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};