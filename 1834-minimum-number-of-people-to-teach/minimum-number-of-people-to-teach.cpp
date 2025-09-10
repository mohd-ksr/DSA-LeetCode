class Solution {
private:
    bool findCommon(int &u, int &v,vector<vector<int>>& languages ){
        unordered_set<int>s1(languages[u-1].begin(), languages[u-1].end());
        unordered_set<int>s2(languages[v-1].begin(), languages[v-1].end());
        for(auto &it:s1){
            if(s2.count(it))return true;
        }
        return false;
    }
    void makeMap(vector<int>&lang, unordered_map<int, int>&langFreq){
        for(auto &l:lang)langFreq[l]++;
    }
    bool present(int &Clang, vector<int>&lang){
        for(auto &l:lang)if(Clang == l)return true;
        return false;
    }
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int>notCommon;
        for(auto &f:friendships){
            int u = f[0];
            int v = f[1];
            if(!findCommon(u,v,languages)){
                notCommon.insert(u);
                notCommon.insert(v);
            }
        }

        unordered_map<int, int>langFreq;
        for(auto &it:notCommon){
            makeMap(languages[it-1],langFreq);
        }

        int commonLang, freq = INT_MIN;
        for(auto &it:langFreq){
            if(it.second > freq){
                commonLang = it.first;
                freq = it.second;
            }
        }
        int ans = 0;
        for(auto &it:notCommon){
            if(!present(commonLang,languages[it-1]))ans++;
        }

        return ans;
    }
};