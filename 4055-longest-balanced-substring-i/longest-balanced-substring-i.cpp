class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 1;
        for(int i=0; i<n; i++){
            unordered_map<int, int>freq;
            for(int j=i; j<n; j++){
                freq[s[j]-'a']++;
                bool ok = true;
                for(auto it:freq){
                    if(it.second>0 && it.second!=freq[s[i]-'a']){
                        ok = false;
                        break;
                    }
                }
                if(ok)ans=max(ans, j-i+1);
            }
        }

        return ans;
    }
};