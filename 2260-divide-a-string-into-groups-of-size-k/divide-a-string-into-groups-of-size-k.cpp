class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        int size = s.length();
        int validNumber = size/k;
        int ind=0;
        for(int i=0; i<validNumber; i++){
            string temp = "";
            for(int j=0; j<k; j++){
                temp.push_back(s[ind++]);
            }
            ans.push_back(temp);
        }

        int remainingChar = size%k;
        if(remainingChar!=0){
            string temp = "";
            while(ind<size){
                temp.push_back(s[ind++]);
                k--;
            }
            while(k--){
                temp.push_back(fill);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};