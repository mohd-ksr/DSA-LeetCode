class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>values;
        values['I']=1;
        values['V']=5;
        values['X']=10;
        values['L']=50;
        values['C']=100;
        values['D']=500;
        values['M']=1000;
        int total=0;
        for(int i=0 ;i<s.length();){
            if(i+1<s.length() && values[s[i]]<values[s[i+1]]){
                total+=values[s[i+1]]-values[s[i]];
                i+=2;
            }
            else{
                total+=values[s[i]];
                i++;
            }
        }
        return total;
    }
};
// Time Complexity O(n)
// Space Complexity O(n)