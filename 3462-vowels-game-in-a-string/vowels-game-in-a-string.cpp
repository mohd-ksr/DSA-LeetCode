class Solution {
private:
    int countVowels(string &s){
        int count = 0;
        for(auto &ch:s){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')count++;
        }
        return count;
    }
public:
    bool doesAliceWin(string s) {
        int vCnt = countVowels(s);
        return vCnt != 0;

    }
};