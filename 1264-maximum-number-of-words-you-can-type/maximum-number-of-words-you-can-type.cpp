class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>s;
        for(auto ch:brokenLetters)s.insert(ch);
        int count = 0;
        bool canType = true;
        for(int i=0; i<=text.size(); i++){
            if(i==text.size() || text[i]==' '){
                if(canType)count++;
                canType = true;
            }
            else if(s.count(text[i])){
                canType = false;
            }
        }
        return count;
    }
};
// Time Complexity O(m+n)