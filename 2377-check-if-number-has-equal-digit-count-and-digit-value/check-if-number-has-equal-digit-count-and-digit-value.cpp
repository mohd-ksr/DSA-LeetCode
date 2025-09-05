class Solution {
public:
    bool digitCount(string num) {
        vector<int>mapp(10,0);
        for(char &ch:num){
            string chr = "";
            chr+=ch;
            mapp[stoi(chr)]++;
        }
        for(int i=0; i<num.size(); i++){
            string chr = "";
            chr+=num[i];
            if(stoi(chr)!=mapp[i])return false;
        }
        return true;
    }
};
// Time complexity O(n)
// space complexity O(1);