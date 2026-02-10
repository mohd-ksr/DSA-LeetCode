class Solution {
private:
    bool solve(string &word, int pos1, string &pat, int pos2){
        if(pos2==pat.size()){
            for(int k=pos1; k<word.size(); k++){
                if(isupper(word[k]))return false;
            }
            return true;
        }
        if(word.size()==pos1) return false;
        if(word[pos1]==pat[pos2])return solve(word, pos1+1, pat, pos2+1);
        if(islower(word[pos1]))return solve(word, pos1+1, pat, pos2);
        return false;
    }
public:
    vector<bool> camelMatch(vector<string>& queries, string pat) {
        vector<bool>ans;
        for(auto &q:queries){
            ans.push_back(solve(q, 0, pat, 0));
        }

        return ans;
    }
};