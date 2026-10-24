class Solution {
private:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;
        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')return true;
        return false;
    }
public:
    string reverseVowels(string s) {
        int i = 0;
        int n = s.size();
        int j = n-1;
        while(i<j){
            while(i<n && !isVowel(s[i]))i++;
            while(j>=0 && !isVowel(s[j]))j--;
            if(i<j)swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};