class Solution {
public:
    bool hasSameDigits(string s) {
        while(true){
            string temp="";
            for(int i=0; i<s.size()-1; i++){
                temp+=to_string(((int)(s[i]-'0')+(int)(s[i+1]-'0'))%10);
            }
            if(temp.size()==2){
                return temp[0]==temp[1];
            }
            s=temp;
        }
        return false;
    }
};