class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(auto str:words){
            int weightedSum = 0;
            for(auto ch:str){
                weightedSum += weights[ch-'a'];
            }
            weightedSum%=26;
            ans +=('a' + (26-weightedSum-1));
        }
        return ans;
    }
};