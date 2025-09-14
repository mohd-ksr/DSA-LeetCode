class Solution {
private:
    bool isVowel(char ch) {
        return ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U';
    }

    string toUpper(string s) {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        return s;
    }

    string devowel(string s) {
        s = toUpper(s);
        for(char &c : s) {
            if(isVowel(c)) c = '*';
        }
        return s;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string,string> caseMap;
        unordered_map<string,string> vowelMap;

        // Preprocess wordlist
        for(auto &word : wordlist) {
            string upper = toUpper(word);
            string vmask = devowel(word);

            // Only store the first occurrence
            if(!caseMap.count(upper)) caseMap[upper] = word;
            if(!vowelMap.count(vmask)) vowelMap[vmask] = word;
        }

        vector<string> ans;
        for(auto q : queries) {
            if(exact.count(q)) {  // Case 1: Exact match
                ans.push_back(q);
                continue;
            }

            string upper = toUpper(q);
            if(caseMap.count(upper)) {  // Case 2: Case-insensitive match
                ans.push_back(caseMap[upper]);
                continue;
            }

            string vmask = devowel(q);
            if(vowelMap.count(vmask)) {  // Case 3: Vowel error match
                ans.push_back(vowelMap[vmask]);
                continue;
            }

            ans.push_back("");  // No match
        }

        return ans;
    }
};
