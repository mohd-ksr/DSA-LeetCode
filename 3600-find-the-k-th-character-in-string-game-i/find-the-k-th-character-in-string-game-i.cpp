class Solution {
public:
    char kthCharacter(int k) {
        string str = "a";
        while(str.length()<k){
            string temp = "";
            for(char ch:str){
                if(ch=='z')temp+='a';
                else temp+=(ch+1);
            }
            str+=temp;
        }
        return str[k-1];
    }
};