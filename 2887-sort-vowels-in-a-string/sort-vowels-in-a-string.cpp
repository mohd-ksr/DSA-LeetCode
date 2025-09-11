class Solution {
private:
    bool isVowel(char &ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'|ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')return true;
        return false;
    }
public:
    string sortVowels(string s) {
        string temp = "";
        for(auto ch:s){
            if(isVowel(ch)) temp+=ch;    
        }
        sort(temp.begin(),temp.end());
        int ind=0;
        for(int i=0; i<s.length(); i++){
            if(isVowel(s[i])) s[i] = temp[ind++];
        }
        return s;
    }
};
// Time complexity O(2n + nlogn)
// Space complexity O(n)