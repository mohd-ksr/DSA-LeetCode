class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        istringstream iss(s);
        string word;
        while(iss >> word){
            words.push_back(word);
        }
        if(pattern.length() != words.size())return false;
        unordered_map<char, string>mapp1;
        unordered_map<string, char>mapp2;
        for(int i=0; i<words.size(); i++){
            if(mapp1.find(pattern[i])!=mapp1.end()){
                if(mapp1[pattern[i]]!=words[i])return false;
            }
            else mapp1[pattern[i]]=words[i];

            if(mapp2.find(words[i])!=mapp2.end()){
                if(mapp2[words[i]]!=pattern[i])return false;
            }
            else mapp2[words[i]]=pattern[i];
        }
        return true;
    }
};
// Time complexity O(n+m)
// space complexity O(n)